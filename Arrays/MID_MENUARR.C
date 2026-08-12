// WAP to insert and delete elements from an array

#include <stdio.h>
#include <conio.h>

int main()
{
    int a[100], i, n, ch = 0, pos, ele;

    clrscr();

    printf("\nEnter the size of array : ");
    scanf("%d", &n);

    // Take array elements
    for(i = 0; i < n; i++)
    {
        printf("\nEnter the element of a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    // Show menu until user chooses Exit
    while(ch != 4)
    {
        printf("\nEnter your choice....");
        printf("\n1. Print array");
        printf("\n2. Insert in array");
        printf("\n3. Delete in array");
        printf("\n4. Exit");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                // Print all elements
                printf("\nElements of array are : ");

                for(i = 0; i < n; i++)
                {
                    printf(" %d", a[i]);
                }

                break;


            case 2:
                // Insert an element at a position
                printf("\nEnter the position to insert : ");
                scanf("%d", &pos);

                printf("\nEnter the element to insert : ");
                scanf("%d", &ele);

                if(pos < 1 || pos > n + 1)
                {
                    printf("\nEnter valid position!!!");
                }
                else
                {
                    // Shift elements to the right
                    for(i = n; i >= pos; i--)
                    {
                        a[i] = a[i - 1];
                    }

                    a[pos - 1] = ele;
                    n++;

                    printf("\nElement inserted successfully...");
                }

                break;


            case 3:
                // Delete an element from a position
                printf("\nEnter the position: ");
                scanf("%d", &pos);

                if(pos < 1 || pos > n)
                {
                    printf("\nInvalid position");
                }
                else
                {
                    // Shift elements to the left
                    for(i = pos - 1; i < n - 1; i++)
                    {
                        a[i] = a[i + 1];
                    }

                    n--;

                    printf("\nElement deleted successfully...");
                }

                break;


            case 4:
                printf("\nExiting program");
                return 0;


            default:
                printf("\nEnter valid choice");
        }
    }

    getch();
    return 0;
}
