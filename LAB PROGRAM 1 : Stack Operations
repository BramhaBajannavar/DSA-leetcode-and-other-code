#include <stdio.h>

#define size 3
int array [size];
int top = -1;

int pop(){
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    else return array[top--];
}

void push (int ele){
    if (top == size -1){ 
        printf("Stack overflow\n");
        printf("%d pushed in stack");
    }
    else array[++top] = ele;
}

void display(){
    if (top >-1 && top < size){
        for (int i=0; i<= top ;++i) printf ("%d  \n", array[i]);
        printf("\n");
    }
    else printf("Stack is empty\n");
}

int main(){
    while (1){
        printf("enter the operation to be performed\n");
        printf ("1.display\n2.pop\n3.push\n4.Exit\n");
        int x;
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            display();
            break;
        case 2:
            printf("%d popped out of the stack\n",pop());
            break;
        case 3:
            printf("Enter element to be pushed\n");
            int y;
            scanf("%d",&y);
            push(y);
            break;
        case 4:
            return 0;
            break;
    
        default:
            break;
        }
    }
}
