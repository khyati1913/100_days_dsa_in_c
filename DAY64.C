// BFS usinf adjacency list and queue (c)
#include<stdio.h>
# include<stdlib.h>
# define MAX 100
// queue implementation
int queue[MAX];
int front = -1,rear = -1;
void enqueue(int x) {
  if (rear == MAX -1) return;
  if (front == -1) front = 0;
  queue[++rear]=x;
}
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}
int isEmpty() {
    return (front == -1 || front > rear);
}
// Adjancency list node
struct Node {
    int vertex;
    struct Node* next;
};
struct Node* adj[MAX];
int visited[MAX];
// create new adjacency node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
// add edge to adjacency list (undirected)
void addEdge( int u, int v) {
    struct Node*  newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}
// BFS function
void BFS(int s, int n) {
    enqueue(s);
    visited[s];
    while (! isEmpty()) {
      int curr = dequeue();
      printf("%d",curr);
      struct Node* temp = adj[curr];
      while (temp != NULL){
        int v = temp->vertex;
        if (!visited[v]) {
            enqueue(v);
            visited[v] = 1;
        }
        temp = temp->next;
      }
    }
}
int main() {
    int n,m,u,v,s;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter number of edges");
    scanf("%d",&n);
    for ( int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }
    printf("Enter edges (u,v) :\n");
    for ( int i = 0; i < m;i++){
        scanf("%d %d",&u,&v);
        addEdge(u,v);
    }
    printf("Enter source vertex:")
    scanf("%d",&s);
    printf("BFS traversal");
    BFS(s,n);
    return 0;
}
