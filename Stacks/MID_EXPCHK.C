#include <stdio.h>
#include <conio.h>

#define MAX 50

int top = -1;
char stack[MAX];
char exp[100];

void push(char ch) {
    if (top == MAX - 1)
        printf("\nStack OverFlow");
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
    int i, flag = 1;
    char ch;
    
    clrscr();
    
    printf("Enter Expression: ");
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
            else if (ch == '[' && exp[i] != ']')
                flag = 0;
            else if (ch == '{' && exp[i] != '}')
                flag = 0;
        }
    }
    
    if (flag == 1 && top == -1)
        printf("\n%s is valid Expression", exp);
    else
        printf("\n%s is not a valid expression", exp);

    getch();
    return 0;
}
