#include<stdio.h>
void input(int a[],int n)
{
     for (int i =0;i<n;i++){
     scanf("%d",&a[i]);
     }
}



int main(){
    int n,m;
    printf("Enter the size of two sorted array");
    scanf("%d%d",&n,&m);
    int a[n];
    int b[m];

    printf("Enter the elements of array which size is %d",n);
    input(a,n);
    printf("Enter the elements of array which size is %d",m);
    input (b,m);
    int size = n+m;
    int c[size];
    int i =0,j=0,k=0;
    while(i<n && j<m ){
    if (a[i]<=b[j])
       {
          c[k]=a[i];
          k++;
          i++;
       }
    else 
       {
          c[k]= b[j];
          k++;
          j++;
       }
    }
    while(i<n)
    {
        c[k]=a[i];
        k++;
        i++;
    }

    while(j<m)
    {
        c[k]=b[j];
        k++;
        j++;
    }
    for (int i =0;i<size;i++)
    {
        printf ("%d ",c[i]);
    }
     
}