#include <stdio.h>

int canAllocate(int a[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (pages + a[i] <= maxPages) {
            pages += a[i];
        } else {
            students++;
            pages = a[i];
        }

        if (students > m)
            return 0;
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[1000];
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        if (a[i] > maxVal) maxVal = a[i];
    }

    int low = maxVal, high = sum, ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canAllocate(a, n, m, mid)) {
            ans = mid;
            high = mid - 1;   // try smaller max
        } else {
            low = mid + 1;    // need larger max
        }
    }

    printf("%d\n", ans);
    return 0;
}
