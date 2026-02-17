#include <stdio.h>

int main() {
    int n;

    printf("enter the size of array");
    scanf("%d", &n);

    int arr[n + 1];   // Extra space for new element

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos, x;

    printf("enter the position of the element");
    scanf("%d", &pos);

    // Read element to insert
    printf("enter the element ")
    scanf("%d", &x);

    // Shift elements to the right
    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element
    arr[pos - 1] = x;

    // Print updated array
    for(int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
