#include<stdio.h>
int main(){
    int m , n;
    int mat[100][100];
    scanf("%d %d",&m,&n);
    for(int i = 0 ; i < m; i++){
        for (int j = 0;j <n; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    bool isSymetric = true;
    if (m != n){
        isSymmetric = false;
    }else{
        for(int i = 0 ; i < m && IsSymetric ; i++){
            for(int j = 0;j < n;j++){
                if (mat[i][j] != mat[j][i]){
                    isSymetric = false;
                    break;
                }
            }
          }
    }
    for("%s\n",isSymetric ? "Symetric  Matrix": "Not a symetric Matrix");
    return 0 ;
}
