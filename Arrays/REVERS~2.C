#include <stdio.h>
int main()
{
    int arr[5], n, i, temp;
    clrscr();
    printf("ENTER THE ARRAY SIZE =>");
    scanf("%d", &n);
    printf("ENTER THE ELMENTS =>\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    printf("REVERSED ARRAY=>\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    getch();

    return 0;
}