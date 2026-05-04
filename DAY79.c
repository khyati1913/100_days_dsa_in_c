#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXV 100
#define MAXE 1000

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[MAXV + 1];

void addEdge(int u, int v, int w) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->w = w;
    node->next = adj[u];
    adj[u] = node;
}

// ---------- Min Heap ----------
struct HeapNode {
    int v, dist;
};

struct HeapNode heap[MAXE];
int heapSize = 0;

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode t = *a; *a = *b; *b = t;
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < heapSize && heap[l].dist < heap[smallest].dist)
        smallest = l;
    if (r < heapSize && heap[r].dist < heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void push(int v, int dist) {
    heap[heapSize].v = v;
    heap[heapSize].dist = dist;
    heapifyUp(heapSize);
    heapSize++;
}

struct HeapNode pop() {
    struct HeapNode root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}
// --------------------------------

int main() {
    int n, m, u, v, w, src;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);  // undirected
    }

    scanf("%d", &src);

    int dist[MAXV + 1];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (heapSize > 0) {
        struct HeapNode top = pop();
        int node = top.v;
        int d = top.dist;

        if (d > dist[node]) continue;

        struct Node* temp = adj[node];
        while (temp) {
            int next = temp->v;
            int weight = temp->w;

            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                push(next, dist[next]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }

    return 0;
}
