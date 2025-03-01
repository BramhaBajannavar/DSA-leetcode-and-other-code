#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
    int data;
    struct s_node* next;
} s_node;

s_node* init(int data) {
    s_node *n = (s_node*)malloc(sizeof(s_node));
    if (n == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); 
    }
    n->data = data;
    n->next = NULL;
    return n;
}

s_node* push(s_node **last, int data, s_node **head) {
    if (*head == NULL) {
       
        *head = init(data);
        *last = *head;  
        return *head;
    }
    
    s_node *l = *last;  
    l->next = init(data); 
    *last = l->next;  
    return l->next;
}

s_node* pop(s_node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to pop.\n");
        return NULL;
    }

    s_node *h = *head;
    if (h->next == NULL) {  
        free(h);
        *head = NULL;
        return NULL;
    }

   
    while (h->next->next != NULL) {
        h = h->next;
    }

    s_node *temp = h->next;
    free(temp);  
    h->next = NULL;  
    return h;
}


void print_list(s_node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    s_node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    s_node *head = NULL;
    s_node *last = NULL;

    int choice, data;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push a node\n");
        printf("2. Pop a node\n");
        printf("3. Print the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter the data to push: ");
                scanf("%d", &data);
                last = push(&last, data, &head);
                break;

            case 2:
                last = pop(&head);
                break;

            case 3:
                print_list(head);
                break;

            case 4:
          
                while (head != NULL) {
                    head = pop(&head);
                }
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
