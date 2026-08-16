#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 100

// Global stack and top pointer
char stack[MAX];
int top = -1;

// Push an element onto the stack
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = ch;
}

// Pop an element from the stack
char pop() {
    if (top == -1) {
        return '\0';
    }
    char ch = stack[top];
    top--;
    return ch;
}

// Helper function to check if the bracket is an opening type
int isOpening(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

// Helper function to check if brackets match
int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int main() {
    char expr[MAX];
    int i, balanced = 1;
    char poppedChar;

    clrscr();

    printf("Enter an expression containing brackets: ");
    gets(expr); 

    // Traverse the string character by character
    for (i = 0; i < strlen(expr); i++) {
        
        // 1. If it's an opening bracket, push it
        if (isOpening(expr[i])) {
            push(expr[i]);
        } 
        // 2. If it's a closing bracket, pop and compare
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            
            // If stack is already empty, an opening bracket is missing
            if (top == -1) {
                balanced = 0; 
                break;
            }
            
            poppedChar = pop();
            
            // If they don't make a valid pair, it's unbalanced
            if (!isMatching(poppedChar, expr[i])) {
                balanced = 0; 
                break;
            }
        }
    }

    // 3. At the end, if stack is not empty, a closing bracket is missing
    if (top != -1) {
        balanced = 0;
    }

    // Display the final result
    if (balanced) {
        printf("The parentheses are Balanced!\n");
    } else {
        printf("The parentheses are Not Balanced!\n");
    }

    getch();
    return 0;
}
