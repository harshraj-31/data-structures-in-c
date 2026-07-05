#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next; // next stores address of next node
};

// a node looks like : [data|next]

// Start always points to the first node
struct node *start = NULL; //  this is a global variable not structure member
struct node *start2;
struct node *start3;

void create();
void display();
void insatstart();
void insatlast();
void insafternode();
void delsatstart();
void delatlast();
void deleteNode();
void count();
void search();
void reverse();
void sort();
void copy_ll();
void dis_copy();
void merge();
int main()
{
    int ch;
    do
    {
        printf("\n1.CREATE");
        printf("\n2.Display");
        printf("\n3.insert at start");
        printf("\n4.insert at end");
        printf("\n5.insert between");
        printf("\n6.Delete at Start");
        printf("\n7.Delete at end");
        printf("\n8.Delete at index");
        printf("\n9.Count");
        printf("\n10.Search");
        printf("\n11. Reverse the list");
        printf("\n12. Sort the List");
        printf("\n13. Copy list");
        printf("\n14. Display copied List");
        printf("\n15. Merge List");
        printf("\n0.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;

        case 2:
            display();
            break;

        case 3:
            insatstart();
            break;

        case 4:
            insatlast();
            break;

        case 5:
            insafternode();
            break;

        case 6:
            delsatstart();
            break;

        case 7:
            delatlast();
            break;

        case 8:
            deleteNode();
            break;

        case 9:
            count();
            break;

        case 10:
            search();
            break;

        case 11:
            reverse();
            break;

        case 12:
            sort();
            break;

        case 13:
            copy_ll();
            break;
        
        case 14:
            dis_copy();
            break;

        case 15:
            merge();
            break;

        case 0:
            printf("Exiting..");
            break;

        default:
            printf("Invalid chocice, try again");
        }
    } while (ch != 0);
}

void create()
{
    // new node and ptr to traverse till end
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\n\tEnter the value for new node: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (start == NULL)
    {
        start = newnode; // if list is empty then we point start to our newnode address; start -> newnode
    }
    else
    {
        ptr = start;              // for traversal
        while (ptr->next != NULL) // [10|*]->[20|*]->[30|NULL] after null break because we have to add newnode at last;
        {
            ptr = ptr->next; // traver till null
        }
        ptr->next = newnode;
    }
}

void display()
{
    struct node *ptr;

    if (start == NULL)
    {
        printf("\nList is Empty");
        return;
    }
    else
    {
        ptr = start;
        printf("\nLinked List: \n");
        while (ptr != NULL)
        {
            printf("%d ->", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL");
    }
}

void insatstart()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the node value: ");
    scanf("%d", &newnode->data);
    if(start == NULL)
    {
        newnode->next = NULL;
        start = newnode;
    }
    newnode->next = start;
    start = newnode;
    printf("\nNode Inserted at start");
}

void insatlast()
{
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the node value: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if(start == NULL)
    {
        start = newnode;
        return;
    }
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    printf("\nNode Inserted at Last");
}

void insafternode()
{
    int srchno;
    struct node *newnode, *ptr;
    if(start == NULL)
    {
        printf("\nList is empty");
        return;
    }
    printf("\nEnter the value after which you want to add the node: ");
    scanf("%d", &srchno);
    ptr = start;

    while (ptr != NULL && ptr->data != srchno)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the node value to insert: ");
        scanf("%d", &newnode->data);
        newnode->next = ptr->next;
        ptr->next = newnode;
        printf("\nNode Inserted after %d", srchno);
    }
    else
    {
        printf("\n%d not Found in the list", srchno);
    }
}
void delsatstart()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nList is Empty");
        return;
    }
    else
    {
        ptr = start;
        start = start->next;
        free(ptr);
    }
}

void delatlast()
{
    struct node *ptr, *p;

    if (start == NULL)
    {
        printf("\nList is Empty");
        return;
    }
    if (start->next == NULL)
    { 
        free(start);
        start = NULL;
        return;
    }
    p = start;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    ptr = p->next;
    p->next = NULL;
    free(ptr);
    //[10|*] -> [20|*]  -> [30|*]  -> [40|NULL]
}

void deleteNode()
{
    int srchno;
    struct node *ptr, *temp;

    if (start == NULL)
    {
        printf("\nList is Empty");
        return;
    }

    printf("\nEnter value to delete: ");
    scanf("%d", &srchno);

    // Case 1: delete first node
    if (start->data == srchno)
    {
        temp = start;
        start = start->next;
        free(temp);
        printf("\nNode deleted");
        return;
    }

    // Case 2: delete middle or last node
    ptr = start;
    //[10|*] -> [20|*]  -> [30|*]  -> [40|NULL]
    while (ptr->next != NULL && ptr->next->data != srchno)
    {
        ptr = ptr->next;
    }

    if (ptr->next == NULL)
    {
        printf("\nValue not found");
        return;
    }

    temp = ptr->next;       // node to be deleted
    ptr->next = temp->next; // bypass node
    free(temp);             // free memory

    printf("\nNode deleted");
}

void count()
{
    int count=0;
    struct node *p;
    if (start == NULL)
    {
        printf("\nList is Empty");
        return;
    }
    p = start;
    while (p != NULL)
    {
        count += 1;
        p = p->next;
    }
    printf("\nTotal nodes are: %d",count);
}

void search()
{
    int key;
    struct node *p;
    if (start == NULL)
    {
        printf("\nList is Empty");
        return;
    }
    printf("\nEnter value to search: ");
    scanf("%d", &key);
    p = start;
    while (p != NULL && p->data != key)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        printf("%d: Number found", key);
    }
    else
    {
        printf(" Number Not found");
    }
}

void reverse()
{
    struct node *curr, *next = NULL, *prev = NULL;
    curr = start;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start = prev;
}
void sort()
{
    struct node *i, *j;
    int temp;
    for (i = start; i != NULL; i = i->next)
    {
        for (j = start; j != NULL; j = j->next)
        {
            if (i->data > j->data)      // THIS IS DESCENDING SORT because of  " > " operator use " < " for  ascsnding sort
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void copy_ll()
{
    

	struct node *ptr,*newnode,*ptr2;
	start2=NULL;

	ptr=start;
	while(ptr!=NULL)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=ptr->data;
		newnode->next=NULL;
     //        START1  
    //  ptr = [10]-> [20]-> [30] -> [40] -> [50] NULL

    //        START2 
    // ptr2 = [10]-> [20]-> [30]-> [40]-> NULL
		if(start2==NULL)
		{
			start2=newnode;
			ptr2=start2;
		}
		else
		{
			ptr2->next=newnode;
			ptr2=newnode;
		}
		ptr=ptr->next;
	}

}
void dis_copy()
{
	struct node *ptr;
	ptr=start2;
	while(ptr!=NULL)
	{
		printf("%d \t",ptr->data);
		ptr=ptr->next;
	}
}

void merge()
{
    struct node *ptr, *newnode, *temp;

    start3 = NULL;

    // Copy first list
    ptr = start;
    while(ptr != NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = ptr->data;
        newnode->next = NULL;

        if(start3 == NULL)
        {
            start3 = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        ptr = ptr->next;
    }

    // Copy second list
    ptr = start2;
    while(ptr != NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = ptr->data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = newnode;

        ptr = ptr->next;
    }

    // Display merged list
    printf("\nMerged List:\n");
    temp = start3;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}