#include <stdio.h>

int main()
{
    int a[100];
    int n, choice, po, val, i;
    clrscr();
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
	scanf("%d", &a[i]);
    }

    while(1)
    {
        printf("\n----- MENU -----\n");
	printf("1. PRINT ARRAY\n");
	printf("2. INSERT DATA\n");
	printf("3. DELETE\n");
	printf("4. EXIT\n");
	printf("ENTER THE CHOICE: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:   // Print Array
		printf("ARRAY OF ELEMENTS:\n");
                for(i = 0; i < n; i++)
                {
		    printf("%d ", a[i]);
                }
                printf("\n");
                break;

            case 2:   // Insert at specific position
		printf("ENTER THE POICISTION: ");
		scanf("%d", &po);
		printf("ENTER THE VALUE");
		scanf("%d", &val);

		if(po < 1 || po > n + 1)
                {
		    printf("INVALID POICISION\n");
                }
                else
                {
		    for(i = n; i >= po; i--)
		    {
			a[i] = a[i - 1];
		    }
		    a[po - 1] = val;
		    n++;
		    printf("VALUE ADD\n");
		}
		break;

	    case 3:   // Delete at specific position
		printf("ENTER THE POSITION: ");
		scanf("%d", &po);

		if(po < 1 || po > n)
		{
		    printf("INVALID POSOTIONS\n");
		}
		else
		{
		    for(i = po - 1; i < n - 1; i++)
		    {
			a[i] = a[i + 1];
		    }
		    n--;
		    printf("VALUE DELETED\n");
		}
		break;

	    case 4:   // Exit
		printf("PROGRAM EXIT\n");
		return 0;

            default:
		printf("ARE YAAR TE KYK KHOTU NAYKHU\n");
	}
    }
}