#include <stdio.h>
#include <limits.h>

#define MAXV 100
#define MAXE 1000

struct Edge {
    int u, v, w;
};

int main() {
    int n, m, src;
    struct Edge edges[MAXE];
    int dist[MAXV];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Relax edges (n-1) times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycle
    int hasNegativeCycle = 0;
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            hasNegativeCycle = 1;
            break;
        }
    }

    if (hasNegativeCycle) {
        printf("NEGATIVE CYCLE\n");
    } else {
        printf("Vertex\tDistance from Source\n");
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX)
                printf("%d\tINF\n", i);
            else
                printf("%d\t%d\n", i, dist[i]);
        }
    }

    return 0;
}
