// Program for insertion in the sorted array
#include <stdio.h>
int main()
{
    int n;
    int a[100];
    printf("Enter the total number of elements  in array");
    scanf("%d", &n);
    printf("Enter value");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the value that to be added ");
    int val;
    scanf("%d",&val);
    int pos=n;
    for (int i = 0; i < n ; i++)
    {
        if (val < a[i])
        {
            pos = i;
            break;
        }
    }
    for (int i = n ; i>pos ;i++ )
    {
        a[i] = a[i-1];
    }
    a[pos]=val;
    n++;  // increment array size after insertion

    for (int i = 0; i < n ; i++)
    {
        printf("%d ", a[i]);
    }
}
