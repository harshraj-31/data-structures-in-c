#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define MAX 5


/* =========================================================
                    NORMAL QUEUE
   ========================================================= */

int queue[MAX];
int front = -1, rear = -1;

void normalEnqueue()
{
    int val;

    if(rear == MAX - 1)
    {
        printf("\nQueue Overflow");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &val);

    if(front == -1)
        front = rear = 0;
    else
        rear++;

    queue[rear] = val;
}

void normalDequeue()
{
    int val;

    if(front == -1 || front > rear)
    {
        printf("\nQueue Underflow");
        return;
    }

    val = queue[front];
    front++;

    printf("\nDeleted: %d", val);

    if(front > rear)
        front = rear = -1;
}

void normalPeek()
{
    if(front == -1)
    {
        printf("\nQueue is empty");
        return;
    }

    printf("\nFront element: %d", queue[front]);
}

void normalDisplay()
{
    int i;

    if(front == -1)
    {
        printf("\nQueue is empty");
        return;
    }

    printf("\nQueue: ");

    for(i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}


/* =========================================================
                    CIRCULAR QUEUE
   ========================================================= */

int cqueue[MAX];
int cfront = -1, crear = -1;

void circularEnqueue()
{
    int val;

    // Queue is full when rear is just before front.
    if((cfront == 0 && crear == MAX - 1) ||
       (cfront == crear + 1))
    {
        printf("\nCircular Queue Overflow");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &val);

    if(cfront == -1)
    {
        cfront = crear = 0;
    }
    else if(crear == MAX - 1)
    {
        crear = 0;
    }
    else
    {
        crear++;
    }

    cqueue[crear] = val;
}

void circularDequeue()
{
    int val;

    if(cfront == -1)
    {
        printf("\nCircular Queue Underflow");
        return;
    }

    val = cqueue[cfront];
    printf("\nDeleted: %d", val);

    if(cfront == crear)
    {
        cfront = crear = -1;
    }
    else if(cfront == MAX - 1)
    {
        cfront = 0;
    }
    else
    {
        cfront++;
    }
}

void circularPeek()
{
    if(cfront == -1)
    {
        printf("\nCircular Queue is empty");
        return;
    }

    printf("\nFront element: %d", cqueue[cfront]);
}

void circularDisplay()
{
    int i;

    if(cfront == -1)
    {
        printf("\nCircular Queue is empty");
        return;
    }

    printf("\nCircular Queue: ");

    if(cfront <= crear)
    {
        for(i = cfront; i <= crear; i++)
            printf("%d ", cqueue[i]);
    }
    else
    {
        // When rear has wrapped around to the beginning.
        for(i = cfront; i < MAX; i++)
            printf("%d ", cqueue[i]);

        for(i = 0; i <= crear; i++)
            printf("%d ", cqueue[i]);
    }
}


/* =========================================================
                  CIRCULAR LINKED LIST
   ========================================================= */

struct cnode
{
    int data;
    struct cnode *next;
};

struct cnode *cstart = NULL;

void circularCreate()
{
    struct cnode *newnode, *ptr;

    newnode = (struct cnode *)malloc(sizeof(struct cnode));

    printf("\nEnter value: ");
    scanf("%d", &newnode->data);

    if(cstart == NULL)
    {
        cstart = newnode;
        newnode->next = cstart;
    }
    else
    {
        ptr = cstart;

        while(ptr->next != cstart)
            ptr = ptr->next;

        ptr->next = newnode;
        newnode->next = cstart;
    }
}

void circularInsertStart()
{
    struct cnode *newnode, *ptr;

    newnode = (struct cnode *)malloc(sizeof(struct cnode));

    printf("\nEnter value: ");
    scanf("%d", &newnode->data);

    if(cstart == NULL)
    {
        cstart = newnode;
        newnode->next = cstart;
        return;
    }

    ptr = cstart;

    while(ptr->next != cstart)
        ptr = ptr->next;

    newnode->next = cstart;
    ptr->next = newnode;
    cstart = newnode;
}

void circularDeleteStart()
{
    struct cnode *ptr, *temp;

    if(cstart == NULL)
    {
        printf("\nList is empty");
        return;
    }

    if(cstart->next == cstart)
    {
        free(cstart);
        cstart = NULL;
        return;
    }

    ptr = cstart;

    while(ptr->next != cstart)
        ptr = ptr->next;

    temp = cstart;
    cstart = cstart->next;
    ptr->next = cstart;

    free(temp);
}

void circularListDisplay()
{
    struct cnode *ptr;

    if(cstart == NULL)
    {
        printf("\nList is empty");
        return;
    }

    ptr = cstart;

    printf("\nCircular List: ");

    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    while(ptr != cstart);

    printf("(START)");
}


/* =========================================================
                    DOUBLY LINKED LIST
   ========================================================= */

struct dnode
{
    int data;
    struct dnode *prev;
    struct dnode *next;
};

struct dnode *dstart = NULL;

void doublyCreate()
{
    struct dnode *newnode, *ptr;

    newnode = (struct dnode *)malloc(sizeof(struct dnode));

    printf("\nEnter value: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(dstart == NULL)
    {
        newnode->prev = NULL;
        dstart = newnode;
    }
    else
    {
        ptr = dstart;

        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = newnode;
        newnode->prev = ptr;
    }
}

void doublyInsertStart()
{
    struct dnode *newnode;

    newnode = (struct dnode *)malloc(sizeof(struct dnode));

    printf("\nEnter value: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;

    if(dstart == NULL)
    {
        newnode->next = NULL;
        dstart = newnode;
    }
    else
    {
        newnode->next = dstart;
        dstart->prev = newnode;
        dstart = newnode;
    }
}

void doublyDeleteStart()
{
    struct dnode *temp;

    if(dstart == NULL)
    {
        printf("\nList is empty");
        return;
    }

    temp = dstart;
    dstart = dstart->next;

    if(dstart != NULL)
        dstart->prev = NULL;

    free(temp);
}

void doublyDisplay()
{
    struct dnode *ptr;

    if(dstart == NULL)
    {
        printf("\nList is empty");
        return;
    }

    ptr = dstart;

    printf("\nDoubly Linked List: ");

    while(ptr != NULL)
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL");
}


/* =========================================================
                       MAIN MENU
   ========================================================= */

int main()
{
    int choice, subchoice;

    clrscr();

    while(1)
    {
        printf("\n\n================================");
        printf("\n       DATA STRUCTURES");
        printf("\n================================");

        printf("\n1. Normal Queue");
        printf("\n2. Circular Queue");
        printf("\n3. Circular Linked List");
        printf("\n4. Doubly Linked List");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);


        switch(choice)
        {
            /* ---------------- Normal Queue ---------------- */

            case 1:

                while(1)
                {
                    printf("\n\n--- Normal Queue ---");
                    printf("\n1. Enqueue");
                    printf("\n2. Dequeue");
                    printf("\n3. Peek");
                    printf("\n4. Display");
                    printf("\n5. Back");

                    printf("\nEnter choice: ");
                    scanf("%d", &subchoice);

                    switch(subchoice)
                    {
                        case 1:
                            normalEnqueue();
                            break;

                        case 2:
                            normalDequeue();
                            break;

                        case 3:
                            normalPeek();
                            break;

                        case 4:
                            normalDisplay();
                            break;

                        case 5:
                            break;

                        default:
                            printf("\nInvalid choice");
                    }

                    if(subchoice == 5)
                        break;
                }

                break;


            /* ---------------- Circular Queue ---------------- */

            case 2:

                while(1)
                {
                    printf("\n\n--- Circular Queue ---");
                    printf("\n1. Enqueue");
                    printf("\n2. Dequeue");
                    printf("\n3. Peek");
                    printf("\n4. Display");
                    printf("\n5. Back");

                    printf("\nEnter choice: ");
                    scanf("%d", &subchoice);

                    switch(subchoice)
                    {
                        case 1:
                            circularEnqueue();
                            break;

                        case 2:
                            circularDequeue();
                            break;

                        case 3:
                            circularPeek();
                            break;

                        case 4:
                            circularDisplay();
                            break;

                        case 5:
                            break;

                        default:
                            printf("\nInvalid choice");
                    }

                    if(subchoice == 5)
                        break;
                }

                break;


            /* ---------------- Circular Linked List ---------------- */

            case 3:

                while(1)
                {
                    printf("\n\n--- Circular Linked List ---");
                    printf("\n1. Create");
                    printf("\n2. Insert at Start");
                    printf("\n3. Delete at Start");
                    printf("\n4. Display");
                    printf("\n5. Back");

                    printf("\nEnter choice: ");
                    scanf("%d", &subchoice);

                    switch(subchoice)
                    {
                        case 1:
                            circularCreate();
                            break;

                        case 2:
                            circularInsertStart();
                            break;

                        case 3:
                            circularDeleteStart();
                            break;

                        case 4:
                            circularListDisplay();
                            break;

                        case 5:
                            break;

                        default:
                            printf("\nInvalid choice");
                    }

                    if(subchoice == 5)
                        break;
                }

                break;


            /* ---------------- Doubly Linked List ---------------- */

            case 4:

                while(1)
                {
                    printf("\n\n--- Doubly Linked List ---");
                    printf("\n1. Create");
                    printf("\n2. Insert at Start");
                    printf("\n3. Delete at Start");
                    printf("\n4. Display");
                    printf("\n5. Back");

                    printf("\nEnter choice: ");
                    scanf("%d", &subchoice);

                    switch(subchoice)
                    {
                        case 1:
                            doublyCreate();
                            break;

                        case 2:
                            doublyInsertStart();
                            break;

                        case 3:
                            doublyDeleteStart();
                            break;

                        case 4:
                            doublyDisplay();
                            break;

                        case 5:
                            break;

                        default:
                            printf("\nInvalid choice");
                    }

                    if(subchoice == 5)
                        break;
                }

                break;


            case 5:
                getch();
                return 0;


            default:
                printf("\nInvalid choice");
        }
    }
}
