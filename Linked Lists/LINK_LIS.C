#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void create();
void display();
void instart();
void lastend();
void linebetween();
void delfirst();
void dellast();
void delbetween();
void count();
void search();
void reverse();
void merge();

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

int main()
{
    int choice;
    clrscr();

    do
    {
        printf("\n---- MENU ----");
        printf("\n1. CREATE");
	printf("\n2. DISPLAY");
        printf("\n3. INSERT AT START");
        printf("\n4. INSERT AT END");
        printf("\n5. INSERT IN BETWEEN");
        printf("\n6. DELETE FIRST");
        printf("\n7. DELETE LAST");
        printf("\n8. DELETE BETWEEN");
        printf("\n9. COUNT NODE");
	printf("\n10.SEARCH NODE");
	printf("\n11.REVERSE");
        printf("\n0. EXIT");
        printf("\nENTER CHOICE => ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: create(); break;
            case 2: display(); break;
            case 3: instart(); break;
            case 4: lastend(); break;
            case 5: linebetween(); break;
	    case 6: delfirst(); break;
            case 7: dellast(); break;
            case 8: delbetween(); break;
            case 9: count(); break;
	    case 10: search(); break;
	    case 11: reverse(); break;
	    case 12:merge();break;

	    case 0: printf("\nPROGRAM END"); break;
            default: printf("\nINVALID CHOICE");
        }
    } while(choice!=0);

    getch();
    return 0;
}

/* CREATE */
void create()
{
    struct node *newnode,*ptr;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value => ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(start==NULL)
        start=newnode;
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newnode;
    }
}

/* DISPLAY */
void display()
{
    struct node *ptr;
    if(start==NULL)
    {
	printf("\nLIST EMPTY");
        return;
    }
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

/* INSERT AT START */
void instart()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value => ");
    scanf("%d",&newnode->data);
    newnode->next=start;
    start=newnode;
}

/* INSERT AT END */
void lastend()
{
    struct node *newnode,*ptr;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value => ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(start==NULL)
        start=newnode;
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newnode;
    }
}

/* INSERT IN BETWEEN */
void linebetween()
{
    int key;
    struct node *newnode,*ptr;
    if(start==NULL)
    {
        printf("\nLIST EMPTY");
        return;
    }
    printf("Insert after value => ");
    scanf("%d",&key);

    ptr=start;
    while(ptr!=NULL && ptr->data!=key)
        ptr=ptr->next;

    if(ptr==NULL)
    {
        printf("\nNOT FOUND");
        return;
    }

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter new value => ");
    scanf("%d",&newnode->data);
    newnode->next=ptr->next;
    ptr->next=newnode;
}

// DELETE FIRST
void delfirst()
{
    struct node *temp;
    if(start==NULL)
        printf("\nLIST EMPTY");
    else
    {
        temp=start;
        start=start->next;
        free(temp);
        printf("\nFIRST NODE DELETED");
    }
}

/* DELETE LAST */
void dellast()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\nLIST EMPTY");
        return;
    }
    if(start->next==NULL)
    {
        free(start);
	start=NULL;
        printf("\nLAST NODE DELETED");
        return;
    }
    ptr=start;
    while(ptr->next->next!=NULL)
        ptr=ptr->next;

    free(ptr->next);
    ptr->next=NULL;
    printf("\nLAST NODE DELETED");
}

/* DELETE BETWEEN */
void delbetween()
{
    int key;
    struct node *ptr,*temp;
    if(start==NULL)
    {
	printf("\nLIST EMPTY");
        return;
    }
    printf("Delete value => ");
    scanf("%d",&key);

    ptr=start;
    while(ptr->next!=NULL && ptr->next->data!=key)
        ptr=ptr->next;

    if(ptr->next==NULL)
    {
        printf("\nNOT FOUND");
        return;
    }

    temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
    printf("\nNODE DELETED");
}

/* COUNT */
void count()
{
    int c=0;
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        c++;
        ptr=ptr->next;
    }
    printf("\nTOTAL NODES = %d",c);
}

/* SEARCH */
void search()
{
    int key,pos=1;
    struct node *ptr=start;
    printf("Search value => ");
    scanf("%d",&key);

    while(ptr!=NULL)
    {
        if(ptr->data==key)
	{
	    printf("\nFOUND AT POSITION %d",pos);
	    return;
	}
	ptr=ptr->next;
	pos++;
    }
    printf("\nNOT FOUND");
}
void reverse()
{
    struct node *curr,*next=NULL,*prew=NULL;
    curr=start;
    while(curr!=NULL){
    next=curr->next;
    curr->next=prew;
    prew=curr;
    curr=next;

    }start=prew;
}
void merge()
{
	struct node *newnode,*ptr;
	int n,i;
	if(start==NULL)
	{
	printf("first node empty");
	return 0;

	ptr=start
	}

}
