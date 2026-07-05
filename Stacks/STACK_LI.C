#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;


void push();
void pop();
void display();
void peep();
void menu();

int main()
{
    int ch;

    clrscr();
    do
    {
        menu();
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                push();
                break;

            case 2:
                display();
                break;

            case 3:
                pop();
                break;

	    case 4:
		peep();
                break;

            case 0:
                exit(0);

            default:
                printf("\n Invalid Choice");
        }
    } while (ch != 0);

    getch();
    return 0;
}
void menu()
{
    printf("\n\n----- STACK MENU -----");
    printf("\n1. Push");
    printf("\n2. Display");
    printf("\n3. Pop");
    printf("\n4. Peep");
    printf("\n0. Exit");
    printf("\nEnter your choice: ");
}

void push()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("\n Stack Overflow");
    }
    else
    {
        printf("\n Enter value: ");
        scanf("%d", &newnode->data);

        newnode->next = top;
        top = newnode;

        printf("\n Value pushed successfully");
    }
}

void pop()
{
    struct node *temp;
	a
    if (top == NULL)
    {
        printf("\n Stack Underflow");
    }
    else
    {
        temp = top;
        printf("\n %d is popped", top->data);
        top = top->next;
        free(temp);
    }
}
void display()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("\n Stack is empty");
    }
    else
    {
        temp = top;
        printf("\n Stack elements are:\n");

        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}
void peep()
{
	if(top==NULL)
   {
    printf("\nSTACK IS EMPTY");
   }
   else
   {
   printf("\n TOP VALUE IS %d",top->data);
   }
}