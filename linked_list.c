#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node * next;
};


struct node* create(int data){
    struct node* newnode= (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert_at_beginning(struct node** head , int data){
    struct node* newnode = create(data);
    newnode->next = *head;
    *head = newnode;
}



void insert_at_end(struct node** head , int data){
    struct node * newnode = create(data);
    if (*head == NULL){
        *head = newnode;
        return;
    }
    struct node* temp = *head;
    while(temp->next!= NULL)temp = temp->next;
    temp->next = newnode;
}



void insert_at_position(struct node** head , int data , int pos){
    struct node* newnode = create(data);
    if (pos <1){
        printf("Invalid location\n");
        return;
    }

    if (pos ==1){
        newnode->next = *head;
        *head = newnode;
        return;
    }

    struct node* temp = *head;
    for (int i=0; temp != NULL && i<pos-1; ++i){
        temp= temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}




void display(struct node** head){
    if (*head == NULL){
        printf("List is empty \n");
        return;
    }
    struct node* temp = *head;
    while(temp != NULL){
        printf("%d ->" , temp->data);
        temp = temp->next;
    }
    printf("NULL \n");


}

int main(){
    struct node* head = NULL;
    int data , position ,x;
    
    while (1){
        printf("Enter choice: \n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at a point\n");
        printf("4. Display\n");
        printf("5 .Exit\n");
        scanf("%d" , &x);
        switch (x)
        {
        case 1:
            printf("Enter the value to be inserted\n");
            int y;
            scanf("%d" ,&y);
            insert_at_beginning(&head , y);
            break;
        
        case 2:
            printf("Enter the value to be inserted\n");
            int z;
            scanf("%d" ,&z);
            insert_at_end(&head ,z);
            break;

        case 3:
            printf("Enter the value to be inserted\n");
            int f;
            scanf("%d" ,&f);
            printf("Enter the position to be inserted at\n");
            int d;
            scanf("%d", &d);
            insert_at_position(&head , f,d);
            break;
        case 4:
            display(&head);
            break;
        case 5:
            return 0;
            break;
        
        default:
            printf("Invalid entry");
            break;
        }
    }
    return 0;
}
