#include <stdio.h>
#include <conio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1)
        printf("\nStack overflow");
    else
        stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        printf("\nStack underflow");
        return '9';
    }
    return stack[top--];
}

int main() {
    char exp[MAX];
    int i, flag = 1;
    char ch;
    
    clrscr();

    printf("Enter an expression: ");
    flushall();
    gets(exp);

    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            ch = pop();

            if (ch == '9') 
                flag = 0;
            else if (ch == '(' && exp[i] != ')')
                flag = 0;
            else if (ch == '{' && exp[i] != '}')
                flag = 0;
            else if (ch == '[' && exp[i] != ']')
                flag = 0;
        }
    }

    // This validation MUST sit outside the loop!
    if (flag == 1 && top == -1)
        printf("\n%s is valid Parentheses\n", exp);
    else
        printf("\n%s is not valid Parentheses\n", exp);

    getch();
    return 0;
}
