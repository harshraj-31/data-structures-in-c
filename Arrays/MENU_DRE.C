#include <stdio.h>
#include <conio.h>

int main()
{
    int a[100];
    int n, choice, po, val, i;

    clrscr();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    // Take array elements from the user
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    while(1)
    {
        printf("\n----- MENU -----\n");
        printf("1. PRINT ARRAY\n");
        printf("2. INSERT DATA\n");
        printf("3. DELETE\n");
        printf("4. EXIT\n");

        printf("ENTER THE CHOICE: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                // Print all elements
                printf("ARRAY OF ELEMENTS:\n");

                for(i = 0; i < n; i++)
                {
                    printf("%d ", a[i]);
                }

                printf("\n");
                break;


            case 2:
                // Insert a value at a given position
                printf("ENTER THE POSITION: ");
                scanf("%d", &po);

                printf("ENTER THE VALUE: ");
                scanf("%d", &val);

                if(po < 1 || po > n + 1)
                {
                    printf("INVALID POSITION\n");
                }
                else
                {
                    // Shift elements right to make space
                    for(i = n; i >= po; i--)
                    {
                        a[i] = a[i - 1];
                    }

                    a[po - 1] = val;
                    n++;

                    printf("VALUE ADDED\n");
                }

                break;


            case 3:
                // Delete the value at a given position
                printf("ENTER THE POSITION: ");
                scanf("%d", &po);

                if(po < 1 || po > n)
                {
                    printf("INVALID POSITION\n");
                }
                else
                {
                    // Shift elements left after deletion
                    for(i = po - 1; i < n - 1; i++)
                    {
                        a[i] = a[i + 1];
                    }

                    n--;

                    printf("VALUE DELETED\n");
                }

                break;


            case 4:
                // Exit the program
                printf("PROGRAM EXIT\n");
                return 0;


            default:
                printf("INVALID CHOICE\n");
        }
    }
}
