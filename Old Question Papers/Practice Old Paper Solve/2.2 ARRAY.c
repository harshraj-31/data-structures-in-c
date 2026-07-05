#include <stdio.h>

int arr[50], n = 0;

// INSERT
void insert()
{
    int pos, val, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n + 1)
    {
        printf("Invalid position\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &val);

    for(i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = val;
    n++;

    printf("Inserted successfully\n");
}

// DELETE
void delete()
{
    int pos, i;

    if(n == 0)
    {
        printf("Array is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n)
    {
        printf("Invalid position\n");
        return;
    }

    for(i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("Deleted successfully\n");
}

// DISPLAY
void display()
{
    int i;

    if(n == 0)
    {
        printf("Array is empty\n");
        return;
    }

    printf("Array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// MAIN
int main()
{
    int choice;

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
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}