#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int no[MAX];
int cnt;
int front = -1, rear = -1;

void enqueue();
void dequeue();
void peek();
void display();
void main()
{ 
    int choice;
    do
    {
        printf("\n1.Enqueue ");
        printf("\n2.Dequeue ");
        printf("\n3.Peek ");
        printf("\n4.Display ");
        printf("\n5.Count");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enqueue(); break;
        
        case 2:
            dequeue(); break;

        case 3:
            peek(); break;

        case 4:
            display(); break;
        
        case 5:
            printf("\nCount: %d",cnt);
            break;

        case 0:
            return;
            break;

        default:
            printf("invalid choice, try again");
        }
    } while (choice != 0);
}

void enqueue()
{
    int val;
    //OVERFLOW
    //F                     R
    //[10] [20] [30] [40] [50]
    if((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        printf("\nOverflow");
        return;
    }

    printf("\nEnter the value: ");
    scanf("%d",&val);

    if(front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if(rear == MAX-1 && front != 0 )
    {
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }

    no[rear] = val;
    cnt++;
}

void dequeue()
{
    int val;
    if(front == -1)
    {
        printf("\nUnderflow!");
        return;
    }

    val = no[front];
    printf("\nDequeue: %d",val);

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == MAX-1)
    {
        front = 0;
    }
    else
    {
        front = front + 1;
    }
    cnt--;
}

void display()
{
   int i;
   if(front == -1)
   {
        printf("\nQueue is empty");
        return;
   }

   //SIMPLE QUEUE
//           FR
   //[1,2,3,4,5]
   if(front <= rear)
   {
        for(i = front; i <= rear; i++)
        {
            printf("%d ", no[i]);
        }
   }
   else
   {

//                 R    F                
    // [ 11 , 12 , 13,  4, 5, 7, 9, 10, 22]
    //    

        for(i = front; i < MAX; i++)
        {
            printf("%d ", no[i]);
        }
         // 4, 5, 7 ,9, 10, 22

        for(i = 0; i <= rear; i++)
        {
            printf("%d ", no[i]);
        }
        // 11, 12, 13
   }
}

//  4, 5, 7, 9, 10, 22, 11, 12, 13

void peek()
{
    if(front == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nPeek: %d",no[front]);
    }
}