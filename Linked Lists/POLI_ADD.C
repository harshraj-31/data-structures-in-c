#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct poly
{
    int c, e;
    struct poly *next;
};

struct poly * addpoly1(struct poly *);
void display1(struct poly *);

struct poly * addpoly2(struct poly *);
void display2(struct poly *);

void menu();
struct poly *p1 = NULL, *p2 = NULL;

/* MAIN */
void main()
{
    clrscr();
    menu();
    getch();
}

/* MENU FUNCTION */
void menu()
{
    int ch;

    do
    {
        printf("\n\n--- POLYNOMIAL MENU ---");
        printf("\n1. Enter Polynomial 1");
        printf("\n2. Display Polynomial 1");
        printf("\n3. Enter Polynomial 2");
        printf("\n4. Display Polynomial 2");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
	{
	    case 1: p1 = addpoly1(p1); break;
	    case 2: display1(p1); break;

	    case 3: p2 = addpoly2(p2); break;
	    case 4: display2(p1); break;

	    case 0: exit(0);
            default: printf("\nInvalid choice");
        }

    } while (ch != 0);
}

/* ADD POLYNOMIAL 1 */
struct poly * addpoly(struct poly *start)
{
    struct poly *p, *temp;
    int c, e;

    printf("\nEnter coefficient (-1 to stop): ");
    scanf("%d", &c);
    printf("Enter exponent: ");
	scanf("%d", &e);
	p = (struct poly *)malloc(sizeof(struct poly));
	p->c = c;
	p->e = e;
	p->next = NULL;

	if (start == NULL)
	{
	    start = p;
	    }
	else
	{
	    temp = start;
	    while (temp->next != NULL)
	    {
	    temp = temp->next;
	    }
	    temp->next = p;
	}
    return start;
}

/* DISPLAY POLYNOMIAL 1 */
void display(struct poly *start)
{
    struct poly *temp = start;

    if (temp == NULL)
    {
	printf("\nPolynomial is empty");
	return;
    }

    while (temp != NULL)
    {
	printf("%dx^%d", temp->c, temp->e);
	if (temp->next != NULL)
	    printf(" + ");
	temp = temp->next;
    }
}
// add poly 2
struct poly * addpoly2(struct poly *start)
{
    struct poly *p, *temp;
    int c, e;

    printf("\nEnter coefficient (-1 to stop): ");
    scanf("%d", &c);
    printf("Enter exponent: ");
	scanf("%d", &e);
	p = (struct poly *)malloc(sizeof(struct poly));
	p->c = c;
	p->e = e;
	p->next = NULL;

	if (start == NULL)
	{
	    start = p;
	    }
	else
	{
	    temp = start;
	    while (temp->next != NULL)
	    {
	    temp = temp->next;
	    }
	    temp->next = p;
	}
    return start;

}

// disply poly 3
void display2(struct poly *start)
{
     struct poly *temp = start;

    if (temp == NULL)
    {
	printf("\nPolynomial is empty");
	return;
    }

    while (temp != NULL)
    {
	printf("%dx^%d", temp->c, temp->e);
	if (temp->next != NULL)
	    printf(" + ");
	temp = temp->next;
    }

}

