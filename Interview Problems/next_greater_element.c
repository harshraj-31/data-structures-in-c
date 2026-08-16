#include <stdio.h>
#include <conio.h>

#define MAX 100

// Stack and top pointer
int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int main() {
    int arr[MAX], res[MAX];
    int n, i;

    clrscr();

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Traverse the array from right to left
    for (i = n - 1; i >= 0; i--) {
        
        // Remove smaller elements from the stack 
        // because they can never be the "Next Greater" for elements to the left
        while (!isEmpty() && stack[top] <= arr[i]) {
            pop();
        }

        // If stack is empty, there is no greater element on the right
        if (isEmpty()) {
            res[i] = -1;
        } 
        // Otherwise, the top of the stack is our Next Greater Element
        else {
            res[i] = stack[top];
        }

        // Push the current element onto the stack for the upcoming elements
        push(arr[i]);
    }

    // Display the final result
    printf("\nElement  -->  Next Greater\n");
    for (i = 0; i < n; i++) {
        printf("   %d     -->       %d\n", arr[i], res[i]);
    }

    getch();
    return 0;
}
