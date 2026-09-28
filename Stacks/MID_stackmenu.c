#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 100 

int stack[MAX];
int top = -1; 

void push(int value) {
    if (top == MAX - 1)
        printf("Stack Overflow! Cannot push %d\n", value);
    else {
        stack[++top] = value;
        printf("%d pushed onto stack\n", value);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow! No elements to pop\n");
    else
        printf("%d popped from stack\n", stack[top--]);
}

void peep() {
    if (top == -1)
        printf("\nStack is empty\n");
    else
        printf("\nTop element is %d\n", stack[top]);
}

void count() {
    printf("Total elements in stack: %d\n", top + 1);
}

void display() {
    int i;
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, value;
    
    clrscr();

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Count\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2: pop(); break;
            case 3: peep(); break;
            case 4: count(); break;
            case 5: display(); break;
            case 6: 
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
