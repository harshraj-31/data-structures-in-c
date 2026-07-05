#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int no[MAX];
int cnt;
int front = -1, rear = -1;

void enqueue();
void dequeue();
void peek();
void display();

int main()  // Should return int, not void
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
            enqueue(); 
            break;
        
        case 2:
            dequeue(); 
            break;

        case 3:
            peek(); 
            break;

        case 4:
            display(); 
            break;
        
        case 5:
            printf("\nCount: %d", cnt);
            break;

        case 0:
            return 0;  // Return 0 for success

        default:
            printf("\nInvalid choice, try again");
        }
    } while (choice != 0);
    
    return 0;
}

// Add element to circular queue
void enqueue()
{
    int val;

    // Check if queue is full
    if((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        printf("\nOverflow");
        return;
    }

    printf("\nEnter the value: ");
    scanf("%d",&val);

    // Initialize queue on first enqueue
    if(front == -1 && rear == -1)
    {
        front = rear = cnt =0;
    }
    // Wrap around to beginning if rear reaches end
    else if(rear == MAX-1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    no[rear] = val;
    cnt++;
}

// Remove element from circular queue
void dequeue()
{
    int val;

    // Check if queue is empty
    if(front == -1)
    {
        printf("\nUnderflow!");
        return;
    }

    val = no[front];
    printf("\nDequeue: %d", val);

    // Reset if only one element
    if(front == rear)
    {
        front = rear = -1;
    }
    // Wrap around to beginning if front reaches end
    else if(front == MAX-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    cnt--;
}

// Display all elements in queue
void display()
{
   int i;

   if(front == -1)
   {
        printf("\nQueue is empty");
        return;
   }

   // Linear display if front <= rear
   if(front <= rear)
   {
        for(i = front; i <= rear; i++)
            printf("%d ", no[i]);
   }
   // Wrapped display if front > rear
   else
   {
        for(i = front; i < MAX; i++)
            printf("%d ", no[i]);
        for(i = 0; i <= rear; i++)
            printf("%d ", no[i]);
   }
}

// Show front element without removing
void peek()
{
    if(front == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nPeek: %d", no[front]);
    }
}