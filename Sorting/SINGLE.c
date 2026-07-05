#include <stdio.h>

int A[50], n;

// Function to input array
void input()
{
    int i;
    printf("ENTER NUMBER OF ELEMENTS => ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
}

// Function to display array
void display()
{
    int i;
    printf("\nARRAY IS: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

// Bubble Sort Function
void bubble()
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            if(A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// Main Function
int main()
{
    input();

    printf("\nBefore Sorting:");
    display();

    bubble();

    printf("\nAfter Sorting:");
    display();

    return 0;
}