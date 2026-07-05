//ARRAY OF SUM & GIVE THE AVERAGEA::
#include <stdio.h>
int main()
{
    int i;
    int num[10] = {1,2,3,4,5,6,7,8,9,10};
    int sum = 0;
    float avg;
    clrscr();
    for(i = 0; i < 10; i++)
    {
	sum = sum+num[i];
    }

    avg = sum / 10.0;

    printf("SUM = %d\n", sum);
    printf("AVERAGE = %.2f\n", avg);
    getch();
    return 0;
}
