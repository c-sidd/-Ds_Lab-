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

/*
🧠 Revision Notes — My Thought Process

1️⃣ Initial Idea:
   - I wanted to merge two sorted arrays.
   - I thought I could just compare the first elements and be done.
   - I didn’t consider what happens after one array finishes early.

// 2️⃣ Mistake:
//    - I used `input(c, size)` thinking it would merge the arrays.
//    - That was wrong—it just takes input, not merges.

3️⃣ Realization:
   - I need to compare all elements using a loop.
   - After one array is exhausted, I must copy the remaining elements.

4️⃣ Improvement:
   - I used a `while(i < n && j < m)` loop to merge.
   - Then added two more `while` loops to copy leftovers from `a` and `b`.

5️⃣ Alternative Thought:
   - I also thought about just appending both arrays and using bubble sort.
   - But that’s inefficient (`O(n^2)`), and I wanted to preserve sorted order efficiently.

6️⃣ Final Learning:
   - Two-pointer merge is optimal for sorted arrays: `O(n + m)` time.
   - Writing clean comments and separating logic helps me revise better.

🧩 Next Steps:
   - Try removing duplicates from merged array.
   - Handle unsorted input by sorting first.
   - Convert this into a reusable function or module for future projects.
*/
