#include <stdio.h>

int lowerBound(int a[], int n, int x) {
    int l = 0, r = n - 1, ans = n;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (a[mid] >= x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int upperBound(int a[], int n, int x) {
    int l = 0, r = n - 1, ans = n;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (a[mid] > x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, x;
    scanf("%d", &n);

    int a[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &x);

    int lb = lowerBound(a, n, x);
    int ub = upperBound(a, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}
