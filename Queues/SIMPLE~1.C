//QUEUE PROGRAM
void enqueue();
void dequeue();
void peek();
void display();

#define MAX 5
int no[MAX];
int front =-1,rear=-1;


void main()
{
	int ch;
	clrscr();
	do{
		printf("\n1. ENqueue /Push");

		printf("\n2. dequeue /Push");
		printf("\n3. peek /Push");
		printf("\n4. display /Push");
		printf("\n0.Exit");
		flushall(); scanf("%d",&ch);

		switch(ch)
		{
			case 1: enqueue(); break;
			case 2: dequeue(); break;
			case 3: peek(); break;
			case 4: display(); break;
			case 0: exit(0);
			default: printf("\n valid choice");
		}//end swith
	}while(ch!=0);
	getch();
}
void enqueue()
{
	int val;
	if (rear == MAX-1)
	{
		printf("QUEUE is full /overflow");
		return;
	}
	else if(front ==-1 && rear == -1)
	{
	front = rear=0;
	}
	else
	{
	      rear=rear+1;
		}
		printf("\n p1 .input value : ");
		scanf("%d",&val);
		no[rear]=val;
}
void dequeue()
{
	if(front ==-1 || front >rear)
	{
		printf("\n1. queue is emplty /underflow");
	}
	else
	{
		printf("\n deleting %d",no[front]);
		front=front+1;
	}

}

void peek()
{
int i;
	if(front == -1 || front >rear)
	{
		printf("queue is empty");
	}
	else
	{


			printf("\n peek : %d",no[front]);

	}
}
void display()
{

int i;
	if(front == -1 || front >rear)
	{
		printf("queue is empty");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("\n%d",no[i]);
		}
	}
}
