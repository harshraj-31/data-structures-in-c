#include <stdio.h>

// Array and current number of elements
int arr[50], n = 0;

// Insert an element at a specific position
void insert()
{
    int pos, val, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    // Check whether the position is valid
    if(pos < 1 || pos > n + 1)
    {
        printf("Invalid position\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &val);

    // Shift elements one position to the right
    for(i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Insert the new value
    arr[pos - 1] = val;
    n++;

    printf("Inserted successfully\n");
}

// Delete an element from a specific position
void delete()
{
    int pos, i;

    // Check whether the array is empty
    if(n == 0)
    {
        printf("Array is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    // Check whether the position is valid
    if(pos < 1 || pos > n)
    {
        printf("Invalid position\n");
        return;
    }

    // Shift elements one position to the left
    for(i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("Deleted successfully\n");
}

// Display all array elements
void display()
{
    int i;

    if(n == 0)
    {
        printf("Array is empty\n");
        return;
    }

    printf("Array: ");

    // Print elements from beginning to end
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Main menu
int main()
{
    int choice;

    // Keep showing the menu until the user exits
    while(1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
