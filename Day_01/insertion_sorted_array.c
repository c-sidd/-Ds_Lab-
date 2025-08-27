#include <stdio.h>

int main() {
    int n;
    int a[100];  // Assuming max size is 100

    // Step 1: Input array size
    printf("Enter the total number of elements in the sorted array: ");
    scanf("%d", &n);

    // Step 2: Input sorted array elements
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Step 3: Input value to insert
    int val;
    printf("Enter the value to be inserted: ");
    scanf("%d", &val);

    // Step 4: Find correct position to insert
    int pos = n;  // Default to end of array
    for (int i = 0; i < n; i++) {
        if (val < a[i]) {
            pos = i;
            break;
        }
    }

    // Step 5: Shift elements to the right
    for (int i = n; i > pos; i--) {
        a[i] = a[i - 1];
    }

    // Step 6: Insert the value
    a[pos] = val;
    n++;  // Update array size

    // Step 7: Print updated array
    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}