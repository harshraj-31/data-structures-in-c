#include <stdio.h>
#include <conio.h>

int main()
{
    int rem = 0, sum = 0, cunt = 0, no;

    clrscr();

    printf("ENTER THE NUMBER: ");
    scanf("%d", &no);

    // Extract each digit, add it to sum, and count the digits.
    while(no > 0)
    {
        rem = no % 10;
        sum += rem;
        cunt++;
        no = no / 10;
    }

    printf("TOTAL %d = ", cunt);
    printf("SUM %d", sum);

    getch();
    return 0;
}
