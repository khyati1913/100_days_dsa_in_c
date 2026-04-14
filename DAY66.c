// detect cycle in a directed graph using DFS and recursion stack
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct Node {
    int vertex;
    struct Node* next;
};
struct Node* adj[MAX];
int visisted[MAX];
int restack[MAX];
int n;
// create adjacency node
struct Node* createNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeod(struct Node));
    node->vetex = v;
    node->next = NULL;
    return node;
}
// add directed edge u ->v
void addEdge(int u,int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
}
// DFS to detect cycle
int dfs(int current) {
    visisted[current] = 1;
    restack[current] = 1;
    struct Node* temp = adj[current];
    while (temp != NULL) {
      int v = temp->vertex;
      if (!visited[v]) {
          if (dfs(v))
              return  1;
      }
      else if (recstack[v]) {
          return 1;
      }
      temp = temp->next;
    }
    recstack[current = 0;
    return 0;
}
int hascycle() {
    for (int i = 0 ; i < n ; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}
int main() {
    int m,u,v;
    scanf("%d %d",&n,&m);
    for (int i = 0 ; i < m;i++){
         adj[i] = NULL;
         visited[i] = 0;
         recstack[i] = 0;
    }
    for ( int i = 0; i < m ; i++) {
        scanf("%d %d",&u,&v);
        addEdge(u,v);
    }
    if (hascycle())
        printf('YES")
    else
        peintf("no')
    return 0;
}
