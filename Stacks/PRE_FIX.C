#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

char stack[50];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1;
        
    return stack[top--];
}

int priority(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
        
    return 0;
}

void reverse(char exp[]) {
    int i, j, len = strlen(exp);
    char temp;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }

    for (i = 0; i < len; i++)
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
}

void infixToPrefix(char infix[], char prefix[]) {
    int i, k = 0;
    char x;

    top = -1;   
    for (i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i]) || isalpha(infix[i]))
            prefix[k++] = infix[i];
            
        else if (infix[i] == '(')
            push(infix[i]);
            
        else if (infix[i] == ')')
            while ((x = pop()) != '(')
                prefix[k++] = x;
                
        else {
            // BUG FIX: changed '>=' to '>' to handle associativity properly after reversal
            while (top != -1 && priority(stack[top]) > priority(infix[i]))
                prefix[k++] = pop();

            push(infix[i]);
        }
    }

    while (top != -1)
        prefix[k++] = pop();

    prefix[k] = '\0';
}

int main() {
    char infix[50], prefix[50];
    
    clrscr();
    
    printf("ENTER THE EXPRESSION: ");
    gets(infix); // Using gets() handles spaces better than scanf("%s")

    reverse(infix);
    infixToPrefix(infix, prefix);
    reverse(prefix);

    printf("Prefix Expression: %s\n", prefix);
    
    getch();
    return 0;
}
