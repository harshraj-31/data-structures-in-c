#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1)
        printf("STACK OVERFLOW\n");
    else
        stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    
    return stack[top--];
}

int precedence(char x) {
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX] = "";
    char ch;
    int i, k = 0;

    clrscr();

    printf("ENTER THE EXPRESSION: ");
    gets(infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        // 1. If it's an operand (letter/number), add it directly to output
        if (isalnum(ch))
            postfix[k++] = ch;
            
        // 2. If it's '(', push it to stack
        else if (ch == '(')
            push(ch);
            
        // 3. If it's ')', pop everything until '(' is found
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            
            pop(); // Remove the '(' from the stack
        } 
        
        // 4. If it's an operator (+, -, *, /, ^)
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            
            push(ch);
        }
    }

    // 5. Pop all remaining operators from the stack to the output
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0'; // Null-terminate the string

    printf("POSTFIX EXPRESSION: %s\n", postfix);
    
    getch();
    return 0;
}
