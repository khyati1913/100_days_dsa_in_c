#include<stdio.h>
int isminheap(int arr[],int n){
    for (int i = 0;i <= (n-2) / 2;i++) {
        int left = 2*i+1;
        int right = 2*i+2;
        if (left < n && arr[i] > arr[left])
          return 0;
        if (right < n && arr[i] >arr[right])
          return 0;
    }
    return 1;
}
int main() {
    int N;
    scanf("%d",&N);
    int arr[N];
    for (int i = 0 ; i < N; i++) {
      scanf("%d",&arr[i]);
    if (isminheap(arr,N))
      printf("YES");
    else 
      printf("NO");
    return 0;
    }
