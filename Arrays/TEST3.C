#include <stdio.h>
#include <conio.h>

int main()
{
    float avg;
    int a[5] = {1,2,3,4,5}, i;
    int sum = 0;

    clrscr();

    // Add all array elements
    for(i = 0; i < 5; i++)
    {
        sum = sum + a[i];
    }

    // Calculate average
    avg = sum / 5.0;

    printf("sum is %d\n", sum);
    printf("avg is %.2f\n", avg);

    getch();
    return 0;
}
