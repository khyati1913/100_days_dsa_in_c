#include<stdio.h>
#include.stdlib.h>
#define MAX 100
struct Node {
    int vertex;
    struct Node* next;
};
struct Node* adj[MAX];
int visited[MAX];
int n;
// create adjacency node
struct Node* createNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}
// add undirected edge
void addEdge(int u,int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
    node = createNode(u);
    node->next = adj[v];
    adj[v] = node;
}
//  dfs to detect cycle
int dfs(int current , int parent){
    visited[current] = 1;
    struct Node* temp = adj[current];
    while (temp != NULL){
        int v = temp->vertex;
        if (!visisted[v]) {
            if (dfs(v,current))
                  return 1;
        }
        else if ( v != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int hashCycle() {
      for ( int i = 0; i < n; i++){
        if (!visited[i]) {
          if (dfs(i,-1))
              return 1;
          }
        }
      }
      return 0;
}
int main() {
      int m,u,v;
      scanf("%d %d",&n,&m);
      for ( int i = 0 ; i  < n; i++) {
          adj[i] = NULL;
          visited[i] = 0;
      }
      for ( int i = 0 ; i < m ; i++) {
          scanf("%d %d",&u,&v);
          addEdge(u,v);
      }
      if (hashCycle())
          printf("YES");
      else
        printf("NO");
      return 0;
}
