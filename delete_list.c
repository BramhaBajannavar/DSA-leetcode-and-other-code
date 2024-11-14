#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create(int data) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty \n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

struct node* create_list() {
    int n;
    printf("Enter how many elements to be inserted in the list: ");
    scanf("%d", &n);

    struct node* head = NULL;
    struct node* temp = NULL;
    struct node* newnode = NULL;

    printf("Enter the elements to be added to linked list:\n");
    for (int i = 0; i < n; ++i) {
        int data;
        scanf("%d", &data);
        newnode = create(data);
        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    return head;
}

void delete_first(struct node** head) {
    if (*head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);  
    printf("First element deleted\n");
}

void delete_last(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Last element deleted\n");
        return;
    }

    struct node* temp = *head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);  
    temp->next = NULL;
    printf("Last element deleted\n");
}

void delete_element(struct node** head, int x) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = *head;
    struct node* prev = NULL;

    if (temp != NULL && temp->data == x) {
        *head = temp->next;  
        free(temp);  
        printf("%d deleted\n", x);
        return;
    }

    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found\n", x);
        return;
    }

    prev->next = temp->next;  
    free(temp); 
    printf("%d deleted\n", x);
}

int main() {
    struct node* head = NULL;
    int x;

    while (1) {
        printf("\nEnter choice: \n");
        printf("1. Create list\n");
        printf("2. Delete beginning\n");
        printf("3. Delete end\n");
        printf("4. Delete element\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        scanf("%d", &x);

        switch (x) {
        case 1:
            head = create_list(); 
            break;
        case 2:
            delete_first(&head); 
            break;
        case 3:
            delete_last(&head);  
            break;
        case 4:
            printf("Enter the value to be deleted: ");
            int f;
            scanf("%d", &f);
            delete_element(&head, f);  
            break;
        case 5:
            display(head);  
            break;
        case 6:
            return 0;  
        default:
            printf("Invalid entry\n");
            break;
        }
    }
    return 0;
}
