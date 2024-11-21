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

// void insert_at_beginning(struct node** head , int data){
//     struct node* newnode = create(data);
//     newnode->next = *head;
//     *head = newnode;
// }



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



// void insert_at_position(struct node** head , int data , int pos){
//     struct node* newnode = create(data);
//     if (pos <1){
//         printf("Invalid location\n");
//         return;
//     }

//     if (pos ==1){
//         newnode->next = *head;
//         *head = newnode;
//         return;
//     }

//     struct node* temp = *head;
//     for (int i=0; temp != NULL && i<pos-1; ++i){
//         temp= temp->next;
//     }

//     if (temp == NULL) {
//         printf("Position out of range\n");
//         return;
//     }

//     newnode->next = temp->next;
//     temp->next = newnode;
// }




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



void sort (struct node** head){
    if (head==NULL)return;

    struct node * i = *head;
    struct node* j;
    int temp;


    while (i!= NULL){
        j= i->next;
        while (j->next!= NULL){
            if (i->data > j->data){
                temp =  i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}



void concatenate(struct node** head1 , struct node** head2){
    if (*head1 == NULL){
        *head1 = *head2;
    }
    else{
        struct node* temp = *head1;
        while (temp->next != NULL)temp = temp->next;
        temp->next = *head2;
    }
}



void reverse (struct node** head){
    struct node* prev = NULL , *current = *head, *next = NULL;

    while (current!= NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main(){
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    int data , position ,x,y,z;
    
    while (1){
        printf("Enter choice: \n");
        printf("1. Insert in list \n");
        printf("2. Sort list \n");    
        printf("3. Reverse list \n");
        printf("4. display list\n");
        printf("5. Concatenate\n");
        printf("6 .Exit\n");
        scanf("%d" , &x);
        switch (x)
        {
        case 1:
            printf("Enter the value to be inserted\n");
            scanf("%d" ,&y);
            printf("Which list?\n");
            scanf("%d", &z);
            if (z == 1)insert_at_end(&head1,y);
            else insert_at_end(&head2,y);
            break;
       
        case 2:
            printf("Which list?\n");
            scanf("%d", &z);
            if (z == 1)sort(&head1);
            else sort(&head2);
            printf("List sorted\n");
            break;

        case 3:
            printf("Which list?\n");
            scanf("%d", &z);
            if (z == 1)reverse(&head1);
            else reverse(&head2);
            printf("List reversed\n");            
            break;

        case 4:
            printf("Which list?\n");
            scanf("%d", &z);
            if (z == 1)display(&head1);
            else display(&head2);
            break;
        

        case 5:
            concatenate(&head1, &head2);
            printf("Lists concatenated\n");
            break;
        
        case 6:
            return 0;
        
        default:
            printf("Invalid entry");
            break;
        }
    }
    return 0;
}
