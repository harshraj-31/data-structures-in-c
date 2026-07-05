#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *ptr, *newnode, *prev;

void create();
void insertstart();
void insertend();
void deletestart();
void deleteend();
void insertend();
void innsertpos();
void deletepos();
void display();

// MAIN FUNCATION
int main()
{
    int choice=-1;
    clrscr();
    do{
	printf("\nMENU\n");
	printf("\n 1.CREATE");
	printf("\n 2.INSERT IN START");
	printf("\n 3.INSERT AT END");
	printf("\n 4.DELETE AT START");
	printf("\n 5.DELETE AT END");
	printf("\n 6.INSERT POSITION");
	printf("\n 7.DELETE POSOTION");
	printf("\n 8.DISPLAY");
	printf("\n 0.EXIT");
	printf("\nENTER YOUR CHOICE: ");
	flushall();
	scanf("%d",&choice);

	switch(choice)
	{
	    case 1:create();
		break;
	    case 2:insertstart();
		break;
	    case 3:insertend();
		break;
	    case 4:deletestart();
		break;
	    case 5:deleteend();
		break;
	    case 6:insertpos();
		break;
	    case 7:deletepos();
		break;
	    case 8:display();
		break;
	    case 0:exit(0);
	}
    }while(choice!=0);

    return 0;
}

// CREATE
void create()
{
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
	printf("OVERFLOW");
	return;
    }

    printf("ENTER VALUE: ");
    scanf("%d",&data);
    newnode->data = data;
    if(start == NULL)
    {
	start = newnode;
	newnode->next = start;
    }
    else
    {
	ptr = start;
	while(ptr->next != start)
	{
	    ptr = ptr->next;
	}
	ptr->next = newnode;
	newnode->next = start;
    }
}
// DISPLAY
void display()
{
    if(start == NULL)
    {
	printf("UNDERFLOW");
	return;
    }
    ptr = start;
    while(ptr->next != start)
    {
	printf("%d -> ", ptr->data);
	ptr = ptr->next;
    }
    printf("%d", ptr->data);
}

// INSERT AT START
void insertstart()
{
    int val;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
	printf("OVERFLOW");
	return;
    }

    printf("ENTER VALUE: ");
    scanf("%d",&val);

    newnode->data = val;

    ptr = start;

    while(ptr->next != start)
    {
	ptr = ptr->next;
    }

    newnode->next = start;
    ptr->next = newnode;
    start = newnode;
}

// INSERT AT END
void insertend()
{
    struct node *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    ptr=start;
    printf("ENTER VALUE DATA: ");
    scanf("%d",&newnode->data);
    while(ptr->next != NULL)
    {
	ptr = ptr->next;
    }
    newnode->next=NULL;
    newnode->prev=ptr;
    ptr ->next=newnode;
}

// DELETE FIRST
void deletestart()
{
    if(start == NULL)
    {
	printf("UNDERFLOW");
	return;
    }
    printf("%d IS DELETE",start->data);
    star=start->next;
    start->prev->NULL;

}

// DELETE END
void deleteend()
{
    if(start == NULL)
    {
	printf("UNDERFLOW");
	return;
    }
    ptr=start;
    while(ptr->next!=start)
    {
      ptr=ptr->next;
    }
    ptr->next=start;
    free(ptr);
}

/* INSERT POSITION
void insertpos()
{

}


// VOID DELETE POSITION
void deletepos()
{

}

*/
