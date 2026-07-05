#include<conio.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start;
struct node *start2;
struct node *start3;
struct node *n;
void del_end()
{
	struct node *ptr;
	ptr=start;
	while(ptr->next->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=NULL;
}
void search()
{
	struct node *ptr;
	int d,flag=0,cnt=0;
	printf("Enter value to search:");
	scanf("%d",&d);
	ptr=start;
	while(ptr->data!=d && ptr->next!=NULL)
	{
		ptr=ptr->next;
		cnt++;
	}
	if(ptr->data==d)
	{
		flag=1;
	}
	if(flag==1)
	{
		printf("\n%d found at %d \n",d,cnt);
	}
	else
	{
		printf("\nNumber not found in list\n");
	}
}
void count()
{
	struct node *ptr,*pt2;
	int cnt=0;
	ptr=start;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
		cnt++;
	}
	printf("\nTotal Nodes in list : %d",cnt);
}
void del_node()
{
	struct node *ptr;
	int d,flag=0;
	printf("Enter value to delete:");
	scanf("%d",&d);
	while(ptr->next->data!=d && ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	if(ptr->next->data==d)
	{
		flag=1;
	}
	if(flag==1)
	{
		ptr->next=ptr->next->next;
	}
	else
	{
		printf("\nNumber not found in list");
	}
}
void del_start()
{
	start=start->next;
}
void ins_end()
{
	struct node *newnode,*ptr;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nInput value :");
	flushall();
	scanf("%d",&newnode->data);
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	newnode->next=NULL;
	ptr->next=newnode;
}
void ins_bet()
{
	struct node *newnode,*ptr;
	int d;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter value to search:");
	scanf("%d",&d);
	printf("\nInput value :");
	flushall();
	scanf("%d",&newnode->data);
	ptr=start;
	while(ptr->data!=d && ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	if(ptr->data==d)
	{
		newnode->next=ptr->next;
		ptr->next=newnode;
	}
	else
		printf("\n%d not found",d);
}
void ins_start()
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nInput value :");
	flushall();
	scanf("%d",&newnode->data);
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		newnode->next=start;
		start=newnode;

	}
}
void create()
{
	struct node *newnode,*ptr;
	newnode=(struct node *)malloc(sizeof(struct node));
	flushall();
	printf("\nInput value :");
	scanf("%d",&newnode->data);
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->next=NULL;
	}
}
void display()
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}
void div_seven()
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->data%7==0)
			printf(" %d\t",ptr->data);
		ptr=ptr->next;
	}
}
void copy_ll()
{
	struct node *ptr,*newnode,*temp;
	start2=NULL;
	ptr=start;
	while(ptr!=NULL)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=ptr->data;
		newnode->next=NULL;
		if(start2==NULL)
		{
			start2=newnode;
			temp=start2;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
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
	struct node *ptr1,*ptr2,*newnode,*temp,*ptr;
	ptr1=start;
	ptr2=start2;
	start3=NULL;
	while(ptr1!=NULL)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=ptr1->data;
		newnode->next=NULL;
		if(start3==NULL)
		{
			start3=newnode;
			temp=start3;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		ptr1=ptr1->next;
	}
	while(ptr2!=NULL)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=ptr2->data;
		newnode->next=NULL;
		temp->next=newnode;
		temp=newnode;
		ptr2=ptr2->next;
	}
	printf("\nMerged Successfully!\n");
	ptr=start3;
	while(ptr!=NULL)
	{
		printf("%d \t",ptr->data);
		ptr=ptr->next;
	}
}
void rev()
{
	struct node *current,*next,*prev=NULL;
	current=start;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	start=prev;
	printf("\nReversed Successfully!");
}
void main()
{

	int ch=0;
	start=NULL;

	clrscr();
	do
	{
		printf("\n1.create\n2.Display\n3.Insert @ start\n4.Insert at end\n5.Insert in between");
		printf("\n6.Delete start\n7.Delete end\n8.Delete specific node \n9.Count total nodes\n");
		printf("10.Search node\n11.Divisible 7\n12.Copy LL");
		printf("\n13.Display LL\n14.Rev Linklist");
		printf("\n15.Merge LL\n0.Exit\n");
		printf("Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				ins_start();
				break;
			case 4:
				ins_end();
				break;
			case 5:
				ins_bet();
				break;

			case 6:
				del_start();
				break;
			case 7:
				del_end();
				break;
			case 8:
				del_node();
				break;
			case 9:
				count();
				break;
			case 10:
				search();
				break;
			case 11:
				div_seven();
				break;
			case 12:
				copy_ll();
				break;
			case 13:
				dis_copy();
				break;
			case 14:
				rev();
				break;
			case 15:
				merge();
				break;
			case 0:
				exit(0);
			default:
				printf("\nEnter appropriate choice");
				break;
		}
	}while(1);
}

