#include<stdio.h>
#include<conio.h>
#define MAX 50

int a[MAX], n;

void input();
void display();
void selection();

void input()
{
   int i;
   printf("ENTER THE NUMBER: ");
   scanf("%d",&n);

   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
}

void display()
{
    int i;
    printf("\nYOUR ARRAY IS: ");
    for(i=0;i<n;i++)
    {
      printf("%d ",a[i]);
    }
}

void selection()
{
    int i,j,min,temp;

    for(i=0;i<n-1;i++)
    {
      min = i;

      for(j=i+1;j<n;j++)
      {
         if(a[j] < a[min])
         {
            min = j;
         }
      }

      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
    }
}

int main()
{
  clrscr();
  input();
  selection();
  display();
  getch();
  return 0;
}