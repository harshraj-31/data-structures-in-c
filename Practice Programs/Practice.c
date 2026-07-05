//CIRCULAR QUEUE

// #include<stdio.h>
// #include<stdlib.h>
// #define MAX 5
// int no[MAX];
// int cnt;
// int front = -1,rear = -1;

// void peek()
// {
//     if(front == -1)
//     {
//         printf("Queue is empty");
//         return;
//     }
//     else
//     {
//         printf("%d",no[front]);
//     }



//NORMAL 
// void enqueue
// {
//     int val;
//     if(rear == MAX -1)
//     {
//         printf("OVERFlow");    
//         return;
//     }
//     if(front == -1 && rear == -1)
//     {
//         front = rear = 0;
//     }
//     else
//     {
//         rear = rear + 1;
//     }
//     no[rear] = val;
// }


//DEQUEUE [ NORMAL]

// void dequeue
// {
//     int val;
//     if(front == -1 || front > rear) 
//     printf("Underflow, nothing to delete");
//     return;

//     else
//     {
//         front = front + 1;
//         printf("Dequeue : %d",no[front]);
//         if(front > rear)
//         {
//             front = rear = -1;
//         }
//     }
// }

//DISPLAY

// void display()
// {
//     int i;
//     if(front == -1 || front > rear) //same as dequeue
//     {
//         printf("Queue is empty");
//         return;
//     }
//     else
//     {
//         for(i=front;i<=rear;i++)
//         {
//             printf("\n%d",no[i]);
//         }
        
//     }
// }


//                               CIRCULAR

// void enqueue
// {
//     if( (front==0 && rear == MAX -1) || (front == rear + 1) )    //P/F (OVERFLOW) return
    
//     if(front == -1 && rear == -1)
//     {
//         front = rear = 0;
//     }
//     else if(rear == MAX -1 && front!=0)
//     {
//         rear = 0;
//     }
//     else
//     {
//         rear = rear +1;  // no[rear]=val 
//     }
//}


//CIRCULAR

// void dequeue()
// {
//     int val;
//     if(front == -1) // UNDERFLOW
//     if(front == rear) // front = rear = -1;
//     else if (front == MAX -1); // front = 0;
//     //PF(DEqueue %d, no[front])
//     else front++;  
// }



// }
// void display()
// {
//     int i;
//     if (front == -1)
//     {
//         printf("Underflow");
//         return;
//     }
//     if(front <= rear)
//     {
//         for(i=front;i<=rear;i++)
//         {
//             printf("%d ",no[i]);
//         }
//     }
//     else
//     {
//          for(i=front;i < MAX;i++)
//         {
//             printf("%d ",no[i]);
//         }
//         for(i=0;i<=rear;i++)
//         {
//             printf("%d ",no[i]);
//         }
//     }
// }
// CIRCULAR LINKED LIST:
// #include<stdio.h>
// #include<stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// struct node *start = NULL;

// void create()
// {
//     struct node *newnode,*ptr;

//     newnode = (struct node*)malloc(sizeof(struct node));
//     printf("Enter value: ");
//     scanf("%d",&newnode->data);

//     if(start == NULL)
//     {
//         start = newnode;
//         newnode->next = start;
//     }
//     else
//     {
//         ptr = start;
//         while(ptr->next != start)
//             ptr = ptr->next;

//         ptr->next = newnode;
//         newnode->next = start;
//     }
// }

// void insatstart()
// {
//     struct node *newnode,*ptr;

//     newnode = (struct node*)malloc(sizeof(struct node));
//     printf("Enter value: ");
//     scanf("%d",&newnode->data);

//     if(start == NULL)
//     {
//         start = newnode;
//         newnode->next = start;
//         return;
//     }

//     ptr = start;
//     while(ptr->next != start)
//         ptr = ptr->next;

//     newnode->next = start;
//     ptr->next = newnode;
//     start = newnode;
// }

// void display()
// {
//     struct node *ptr;

//     if(start == NULL)
//     {
//         printf("List empty");
//         return;
//     }

//     ptr = start;
//     do
//     {
//         printf("%d -> ",ptr->data);
//         ptr = ptr->next;
//     }while(ptr != start);

//     printf("(start)");
// }

// void delatstart()
// {
//     struct node *ptr,*temp;

//     if(start == NULL)
//         return;

//     ptr = start;
//     while(ptr->next != start)
//         ptr = ptr->next;

//     temp = start;
//     start = start->next;
//     ptr->next = start;
//     free(temp);
// }


// DOUBLY LINKED LIST:
// #include<stdio.h>
// #include<stdlib.h>

// struct node
// {
//     int data;
//     struct node *prev;
//     struct node *next;
// };

// struct node *start = NULL;

// void create()
// {
//     struct node *newnode,*ptr;

//     newnode = (struct node*)malloc(sizeof(struct node));
//     printf("Enter value: ");
//     scanf("%d",&newnode->data);

//     newnode->next = NULL;

//     if(start == NULL)
//     {
//         newnode->prev = NULL;
//         start = newnode;
//     }
//     else
//     {
//         ptr = start;
//         while(ptr->next != NULL)
//             ptr = ptr->next;

//         ptr->next = newnode;
//         newnode->prev = ptr;
//     }
// }

// void insatstart()
// {
//     struct node *newnode;

//     newnode = (struct node*)malloc(sizeof(struct node));
//     printf("Enter value: ");
//     scanf("%d", &newnode->data);
//     newnode->prev = NULL;

//     if(start == NULL)  // List is empty
//     {
//         newnode->next = NULL;
//         start = newnode;
//     }
//     else  // List has nodes
//     {
//         newnode->next = start;
//         start->prev = newnode;
//         start = newnode;
//     }
// }

// void display()
// {
//     struct node *ptr;

//     ptr = start;

//     while(ptr != NULL)
//     {
//         printf("%d -> ",ptr->data);
//         ptr = ptr->next;
//     }

//     printf("NULL");
// }

// void delatstart()
// {
//     struct node *temp;

//     if(start == NULL)
//         return;

//     temp = start;
//     start = start->next;

//     if(start != NULL)
//         start->prev = NULL;

//     free(temp);
// }