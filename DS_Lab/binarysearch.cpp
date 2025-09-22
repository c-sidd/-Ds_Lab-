#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[7]={1,2,3,4,5,6,7};
    int key =6;
    int min = 0;
    int max = 7-1;
    int mid ;
    while(min<=max)
    {   mid = (min+max)/2;
          if(arr[mid]<key)
          {
            min = mid+1;
            
          }
          else if (arr[mid]>key)
          {
            max = mid-1;
          
          }
          else{
            cout<< mid;
            break;}

    }
}