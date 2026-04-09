#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int n;
    struct Node** adj;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->n = n;
    graph->adj = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        graph->adj[i] = NULL;
    return graph;
}

// Undirected edge
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* node = createNode(v);
    node->next = graph->adj[u];
    graph->adj[u] = node;

    node = createNode(u);
    node->next = graph->adj[v];
    graph->adj[v] = node;
}

void dfs(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->vertex])
            dfs(graph, temp->vertex, visited);
        temp = temp->next;
    }
}

int main() {
    int n, m, u, v, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Graph* graph = createGraph(n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    dfs(graph, s, visited);

    return 0;
}
