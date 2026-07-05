#include <stdio.h>
#include <conio.h>
int isPrime(int n)
{
    int i;
    if(n < 2)
	return 0;

    for(i = 2; i <= n/2; i++)
    {
	if(n % i == 0)
	    return 0;
    }
    return 1;
}
int main()
{
    clrscr();
    int num, temp, digit, count = 0, pow = 1, rotate, i;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = num;
    while(temp > 0)
    {
	count++;
	temp = temp / 10;
    }
    for(i = 1; i < count; i++)
	pow = pow * 10;
	temp = num;
    for(i = 0; i < count; i++)
    {
	if(!isPrime(temp))
	{
	    printf("Not a Circular Prime");
	    getch();
	    return 0;
	}
	digit = temp % 10;
	rotate = (digit * pow) + (temp / 10);
	temp = rotate;
    }
    printf("Circular Prime Number");
    getch();
    return 0;
}