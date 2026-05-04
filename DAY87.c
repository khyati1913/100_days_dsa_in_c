#include <stdio.h>

int binarySearch(int a[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;  // not found
}

int main() {
    int n, x;
    scanf("%d", &n);

    int a[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Ensure array is sorted before binary search
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    scanf("%d", &x);

    int idx = binarySearch(a, n, x);

    if (idx != -1)
        printf("FOUND at index %d\n", idx);
    else
        printf("NOT FOUND\n");

    return 0;
}
