// WAP to insert and delete elements from an array

#include <stdio.h>
#include <conio.h>

int main()
{
    int a[100], i, n, ch = 0, pos, ele;

    clrscr();

    printf("\nEnter the size of array : ");
    scanf("%d", &n);

    // Enter array elements
    for(i = 0; i < n; i++)
    {
        printf("\nEnter the element of a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    while(ch != 4)
    {
        printf("\n\nEnter your choice....");
        printf("\n1. Print array");
        printf("\n2. Insert in array");
        printf("\n3. Delete from array");
        printf("\n4. Exit");

        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                // Display all array elements
                printf("\nElements of array are : ");

                for(i = 0; i < n; i++)
                {
                    printf(" %d", a[i]);
                }

                break;


            case 2:
                // Take position and element to insert
                printf("\nEnter the position to insert : ");
                scanf("%d", &pos);

                printf("\nEnter the element to insert : ");
                scanf("%d", &ele);

                if(pos < 1 || pos > n + 1)
                {
                    printf("\nEnter a valid position!!!");
                    break;
                }

                // Shift elements one position to the right
                for(i = n; i >= pos; i--)
                {
                    a[i] = a[i - 1];
                }

                a[pos - 1] = ele;
                n++;

                printf("\nElement inserted successfully...");

                break;


            case 3:
                // Take the position of element to delete
                printf("\nEnter the position: ");
                scanf("%d", &pos);

                if(pos < 1 || pos > n)
                {
                    printf("\nInvalid position");
                }
                else
                {
                    // Shift elements one position to the left
                    for(i = pos - 1; i < n - 1; i++)
                    {
                        a[i] = a[i + 1];
                    }

                    n--;

                    printf("\nElement deleted successfully...");
                }

                break;


            case 4:
                printf("\nExiting program...");
                return 0;


            default:
                printf("\nEnter a valid choice");
        }
    }

    getch();
    return 0;
}
