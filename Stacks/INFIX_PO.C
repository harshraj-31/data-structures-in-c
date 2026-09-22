#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

char postfix[MAX];
int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int i, op1, op2, result = 0;

    clrscr();
    printf("ENTER THE POSTFIX EXPRESSION: ");
    gets(postfix);

    for (i = 0; postfix[i] != '\0'; i++)
        if (isdigit(postfix[i]))
            push(postfix[i] - '0');
        else {
            op2 = pop();
            op1 = pop();

            switch (postfix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '%': result = op1 % op2; break;
                case '^': result = pow(op1, op2); break;
            }
            push(result);
        }

    // The final result is always the last item left on the stack
    printf("RESULT = %d\n", stack[top]);
    
    getch();
    return 0;
}
