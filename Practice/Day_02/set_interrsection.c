#include <stdio.h>

void input(int a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

int main() {
    int n, m;
    printf("Enter the size of two arrays: ");
    scanf("%d %d", &n, &m);

    int a[n], b[m];

    printf("Enter the elements of the first array (size %d): ", n);
    input(a, n);

    printf("Enter the elements of the second array (size %d): ", m);
    input(b, m);

    int size = n + m;
    int c[size];
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] == b[j]) {
            c[k++] = a[i++];
            j++;
        } else {
           j++;
        }
    }

    // while (i < n) {
    //     c[k++] = a[i++];
    // }

    // while (j < m) {
    //     c[k++] = b[j++];
    // }

    printf("intersection array: ");
    for (int x = 0; x < k; x++) {
        printf("%d ", c[x]);
    }
    printf("\n");

    return 0;
}
