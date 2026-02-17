#include<stdio.h>
int main(){
      int n,k ,comparisons = 0;
      int arr[100];
      int found = -1;
      scanf("%d",&n;
      for(int i = 0 ; i < n; i++){
            scanf("%d",&arr[i]);
      }
      scanf("%d",&k);
      for(int i=0;i<n;i++){
         comparisons++;
         if (arr[i] == k){
                found = i;
                break;
         }
      }
      if (found != -1 ){
         printf("Found at index %d\n",found);
      }else{
          printf("not found \n);
      }
      printf("comparisons = %d\n",comparisons);
      return 0 ;
}
