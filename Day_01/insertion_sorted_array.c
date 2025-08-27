#include <stdio.h>

int main() {
    int n;
    int a[100];  

   
    printf("Enter the total number of elements in the sorted array: ");
    scanf("%d", &n);

   
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

  
    int val;
    printf("Enter the value to be inserted: ");
    scanf("%d", &val);

   
    int pos = n; 
    for (int i = 0; i < n; i++) {
        if (val < a[i]) {
            pos = i;
            break;
        }
    }


    for (int i = n; i > pos; i--) {
        a[i] = a[i - 1];
    }

    a[pos] = val;
    n++;  


    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}