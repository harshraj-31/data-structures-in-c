// Find the sum and average of 10 array elements

#include <stdio.h>

int main()
{
    int i;
    int num[10] = {1,2,3,4,5,6,7,8,9,10};
    int sum = 0;
    float avg;

    clrscr();

    // Add all array elements
    for(i = 0; i < 10; i++)
    {
        sum = sum + num[i];
    }

    // Calculate average
    avg = sum / 10.0;

    printf("SUM = %d\n", sum);
    printf("AVERAGE = %.2f\n", avg);

    getch();
    return 0;
}
