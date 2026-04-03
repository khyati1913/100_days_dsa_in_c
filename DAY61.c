#include<stdio.h>
int main() {
    int n , m, type;
    scanf("%d",&n);
    scanf("%d",&m);
    int adj[n][n];
    // initialize matrix with 0
    for ( int i = 0; i < n ; i++)c
      for(int j = 0; j < n ; j++)
          adj[i][j] = 0;
    // read edges
    for (int i = 0 ; i < m ; i++) {
        int u , v;
        scanf("%d %d",&u,&v);
        adj[u][v] = 1;
        // if unidirected , add reverse edge later after reading type
    }
    scanf("%d",&type);
    if (type == 0){
      for (int i = 0 ; i < n; i++)
          for (int j = 0 ; j < n;j++)
            if (adj[i][j] == 1)
                  adj[j][i] = 1;
    }  
