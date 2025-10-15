#include<stdio.h>
int main()
{
   
   int n;
   printf("Enter the total elements");
   scanf("%d",&n);
   int arr[n];
   for (int i =0;i<n;i++)
   {
      scanf("%d",&arr[i]);
   }
   for (int i =0;i<n-1;i++)
   {
      if(arr[i+1]!=(arr[i]+1))
      {
         printf("the missing element is %d",(arr[i]+1));
         break;
         
      }
   }
  
}