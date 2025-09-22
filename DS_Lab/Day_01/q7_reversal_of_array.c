#include<stdio.h>
int main()
{
    int arr[]={1,2,3,4,5,6,7};
  int i=0;
   int  j= (sizeof(arr)/sizeof(int))-1;
   while(i<j){
     arr[i]=arr[j]+arr[i];
     arr[j]=arr[i]-arr[j];
     arr[i]=arr[i]-arr[j];
    i++;
    j--;}

     for (int i =0;i<(sizeof(arr)/sizeof(int));i++)
     {
              printf("%d ",arr[i]);
     }


}