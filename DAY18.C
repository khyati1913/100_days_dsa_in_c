#include<stdio.h>
void reverse(int arr[] ; int start ; int end){
     while ( starat < end){
         int tmp = arr[start];
         arr[atart] = arr[end];
         arr[end] = tmp; 
         start++;
         end--;
     }
}
int main(){
    int n,k;
    int arr[100];
    scanf("%d",&n);
    for(int i = 0 ; i < n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&k);
    k = k % n;
    reverse(arr,0,n -1);
    reverse(arr,0,k - 1);
    reverse(arr,0,n - 1);


   for ( int i = 0 ; i < n; i++){
       printf("%d",arr[i]);
       if ( i < (n - 1) printf(" ");
  }
  printf("\n");
  rerurn 0 ; 
)
