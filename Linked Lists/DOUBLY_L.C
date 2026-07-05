#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// STRUCTURE
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL, *newnode, *ptr, *temp;

// FUNCTION DECLARATION
void create();
void insertstart();
void insertend();
void deletestart();
void deleteend();
void display();

// MAIN
void main()
{
    int choice;
    clrscr();

    do{
        printf("\n\n===== DOUBLY LINKED LIST MENU =====\n");
        printf("1. CREATE NODE (AT END)\n");
        printf("2. INSERT AT START\n");
        printf("3. INSERT AT END\n");
        printf("4. DELETE FROM START\n");
        printf("5. DELETE FROM END\n");
        printf("6. DISPLAY\n");
        printf("0. EXIT\n");

        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: create(); break;
            case 2: insertstart(); break;
            case 3: insertend(); break;
	    case 4: deletestart(); break;
	    case 5: deleteend(); break;
	    case 6: display(); break;
	}

    }while(choice != 0);

    getch();
}
void create()
{
    insertend();
}



void insertstart()
{
    int data;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
	printf("OVERFLOW");
	return;
    }

    printf("ENTER DATA: ");
    scanf("%d",&data);

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = start;

    if(start != NULL)
	start->prev = newnode;

    start = newnode;
}


void insertend()
{
    int data;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
	printf("OVERFLOW");
	return;
    }

    printf("ENTER DATA: ");
    scanf("%d",&data);

    newnode->data = data;
    newnode->next = NULL;

    if(start == NULL)
    {
	newnode->prev = NULL;
	start = newnode;
    }
    else
    {
	ptr = start;

	while(ptr->next != NULL)
	    ptr = ptr->next;

	ptr->next = newnode;
	newnode->prev = ptr;
    }
}

// DELETE START
void deletestart()
{
    if(start == NULL)
    {
	printf("LIST IS EMPTY");
	return;
    }

    temp = start;
    start = start->next;

    if(start != NULL)
	start->prev = NULL;

    printf("DELETED ELEMENT: %d", temp->data);
    free(temp);
}


// DELETE START
void deleteend()
{
    if(start == NULL)
    {
	printf("LIST IS EMPTY");
	return;
    }
    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;

    if(ptr->prev == NULL)
        start = NULL;
    else
        ptr->prev->next = NULL;

    printf("DELETED ELEMENT: %d", ptr->data);
    free(ptr);
}


// DSIPLAY FUNCATION
void display()
{
    if(start == NULL)
    {
        printf("LIST IS EMPTY");
        return;
    }
    ptr = start;
    printf("\nFORWARD: ");
    while(ptr != NULL)
    {
	printf("%d ", ptr->data);
	if(ptr->next == NULL)
	    break;
	ptr = ptr->next;
    }
    printf("\nBACKWARD: ");
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
}