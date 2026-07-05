//WRITE A PROGRAM TO ACCESS ARRAY ALIMENT UNING POINTER :
#include <stdio.h>
int main()
{
    int a[10] = {10, 20, 30, 40, 50,60,70,80,90,100};
    int *p,i;

    clrscr();
   p = a;
    for(i = 0; i < 10; i++)
    {
	printf("ELEMENTS =>%d=%d\n ", i,*(p+i));
    }
    getch();
    return 0;
}