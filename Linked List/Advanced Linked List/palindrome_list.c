/*
 * Palindrome List
 */

#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 2, 1};
    int n = 5;
    int i, palindrome = 1;

    // Compare elements from both ends
    for(i = 0; i < n / 2; i++)
    {
        if(arr[i] != arr[n - i - 1])
        {
            palindrome = 0;
            break;
        }
    }

    // Check the result
    if(palindrome == 1)
    {
        printf("List is Palindrome");
    }
    else
    {
        printf("List is Not Palindrome");
    }

    return 0;
}
