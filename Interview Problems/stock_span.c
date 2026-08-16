#include <stdio.h>
#include <conio.h>

#define MAX 100

// Stack to store indices
int stack[MAX];
int top = -1;

int main() {
    int price[MAX], span[MAX];
    int n, i;

    clrscr();

    printf("Enter number of days: ");
    scanf("%d", &n);

    printf("Enter the stock prices:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    // Process the stock span for each day
    for (i = 0; i < n; i++) {
        
        // Remove days from the stack if their price is less than or equal to today's price
        // They are no longer useful because today's price is higher and acts as a block
        while (top != -1 && price[stack[top]] <= price[i]) {
            top--;
        }

        // If stack becomes empty, today's price is the highest so far
        if (top == -1) {
            span[i] = i + 1;
        } 
        // Otherwise, the span is the difference between today and the last highest day
        else {
            span[i] = i - stack[top];
        }

        // Push today's index onto the stack for future days to compare
        top++;
        stack[top] = i;
    }

    // Display the final result
    printf("\nDay\tPrice\tSpan\n");
    printf("------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, price[i], span[i]);
    }

    getch();
    return 0;
}
