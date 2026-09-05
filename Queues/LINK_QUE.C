#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

void create_queue(struct queue *);
void insert(struct queue *, int);
void delete_node(struct queue *);
void display(struct queue *);
void peek(struct queue *);
void menu(struct queue *);

void create_queue(struct queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void insert(struct queue *q, int val)
{
    struct node *ptr;

    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }

    ptr->data = val;
    ptr->next = NULL;

    if (q->front == NULL)
    {
        q->front = ptr;
        q->rear = ptr;
    }
    else
    {
        q->rear->next = ptr;
        q->rear = ptr;
    }

    printf("DATA INSERTED\n");
}

void delete_node(struct queue *q)
{
    struct node *ptr;

    if (q->front == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }

    ptr = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    printf("DELETED ELEMENT: %d\n", ptr->data);
    free(ptr);
}

void display(struct queue *q)
{
    struct node *temp;

    if (q->front == NULL)
    {
        printf("EMPTY\n");
        return;
    }

    temp = q->front;

    printf("QUEUE ELEMENTS: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void peek(struct queue *q)
{
    if (q->front == NULL)
    {
        printf("EMPTY\n");
    }
    else
    {
        printf("FIRST ELEMENT IS: %d\n", q->front->data);
    }
}

void menu(struct queue *q)
{
    int choice, value;

    while (1)
    {
        printf("\n1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. PEEK\n");
        printf("0. EXIT\n");

        printf("ENTER THE CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("ENTER THE VALUE: ");
                scanf("%d", &value);
                insert(q, value);
                break;

            case 2:
                delete_node(q);
                break;

            case 3:
                display(q);
                break;

            case 4:
                peek(q);
                break;

            case 0:
                exit(0);

            default:
                printf("INVALID CHOICE\n");
        }
    }
}

int main()
{
    struct queue q;

    create_queue(&q);
    menu(&q);

    return 0;
}
