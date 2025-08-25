// Program to insert the given elements into an array.
#include<stdio.h>

int main()

{
    int arr[100]={6,7,8,9,3,4,5};
    int index,value;
    printf("Enter the position at which the value is added and the value ");
    scanf("%d%d",&index,&value);
    for (int i =74;i>=index;i--)
    {
        arr[i]= arr[i-1];

    }
    arr[index] = value;


 for (int i =0;i<8;i++)
    {
        printf("%d ",arr[i]);
    }

    
}
