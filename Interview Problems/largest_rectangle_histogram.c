#include <stdio.h>
#include <conio.h>

#define MAX 100

int main() {
    int hist[MAX];
    int n, i = 0;
    
    // Stack to store the indices of the histogram bars
    int stack[MAX];
    int top = -1;
    
    int max_area = 0;
    int current_area = 0;
    int popped_index;
    int width;

    clrscr();

    printf("Enter number of bars: ");
    scanf("%d", &n);

    printf("Enter the heights of the bars:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &hist[i]);
    }

    i = 0;
    // Traverse all the bars in the histogram
    while (i < n) {
        // If stack is empty or current bar is taller/equal, push its index
        if (top == -1 || hist[stack[top]] <= hist[i]) {
            top++;
            stack[top] = i;
            i++;
        } 
        // If current bar is shorter, calculate area for the top of the stack
        else {
            popped_index = stack[top];
            top--;

            // Calculate width for the popped bar
            if (top == -1) {
                width = i; // If stack is empty, it extends all the way back
            } else {
                width = i - stack[top] - 1; // Distance between current index and new top
            }

            // Calculate area and update max_area if needed
            current_area = hist[popped_index] * width;
            if (current_area > max_area) {
                max_area = current_area;
            }
        }
    }

    // Pop the remaining bars in the stack and calculate their areas
    while (top != -1) {
        popped_index = stack[top];
        top--;

        if (top == -1) {
            width = i;
        } else {
            width = i - stack[top] - 1;
        }

        current_area = hist[popped_index] * width;
        if (current_area > max_area) {
            max_area = current_area;
        }
    }

    printf("\nThe area of the largest rectangle is: %d\n", max_area);

    getch();
    return 0;
}
