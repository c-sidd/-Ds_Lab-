#include<stdio.h>
int main()
{
      int n;
      int a[100];
      printf("Enter the total number of elements in array");
       scanf("%d",&n);
       printf("Enter value");
      for (int i =0;i<n;i++)
      {
        scanf("%d",&a[i]);
      }
     printf("Enter the position fromm which the value is deleted");
     int pos;
     scanf("%d",&pos);
     for (int i = pos-1 ;i<n-1;i++)
     {
        a[i]= a[i+1];
     }
     for (int i =0;i<n-1;i++)
      {
        printf("%d ",a[i]);
      }
}