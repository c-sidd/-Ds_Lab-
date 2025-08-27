//Program to find which element is repeated in the array and which is not

#include<stdio.h>
int main()
{    
    int arr[]={1,2,3,4,5,2,3,4,2,1};
    int max =0;
    for (int i =0;i<sizeof(arr)/sizeof(int);i++)
    {
        if (arr[i]>max)
           max = arr[i];
    }
    int a[max+1];
    for (int i =0;i<=max;i++)
    {
        a[i]=0;
    }

    for (int i =0;i<sizeof(arr)/sizeof(int);i++)
    {
         int index = arr[i];
             a[index]++;
    }
    for (int i =0;i<=max;i++)
    {
        if (a[i]!=0)
          printf("This elment %d repeats this %d time \n",i,a[i]);
    }
}