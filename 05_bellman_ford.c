/* Experiment 5: Bellman-Ford shortest paths.
   Directed graph: enter edges as source, destination, weight.
   Vertices are numbered 0 to n-1. Negative weights are allowed.
*/
#include <stdio.h>

#define MAXV 20
#define MAXE 100
#define INF 999999

struct Edge {
    int from, to, weight;
};

int main(void) {
    struct Edge edges[MAXE];
    int n, m, source, i, j, changed;
    int dist[MAXV];

    printf("Enter number of vertices (1-%d): ", MAXV);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXV) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter number of directed edges (0-%d): ", MAXE);
    if (scanf("%d", &m) != 1 || m < 0 || m > MAXE) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    printf("Enter each edge as: from to weight\n");
    for (i = 0; i < m; i++) {
        if (scanf("%d %d %d", &edges[i].from, &edges[i].to,
                  &edges[i].weight) != 3) {
            printf("Invalid edge input.\n");
            return 1;
        }
        if (edges[i].from < 0 || edges[i].from >= n ||
            edges[i].to < 0 || edges[i].to >= n) {
            printf("Vertex numbers must be from 0 to %d.\n", n - 1);
            return 1;
        }
    }

    printf("Enter source vertex (0-%d): ", n - 1);
    if (scanf("%d", &source) != 1 || source < 0 || source >= n) {
        printf("Invalid source vertex.\n");
        return 1;
    }

    for (i = 0; i < n; i++) dist[i] = INF;
    dist[source] = 0;

    /* Relax all edges n-1 times. */
    for (i = 1; i <= n - 1; i++) {
        changed = 0;
        for (j = 0; j < m; j++) {
            int u = edges[j].from;
            int v = edges[j].to;
            int w = edges[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                changed = 1;
            }
        }
        if (!changed) break;
    }

    /* Check for a negative-weight cycle reachable from source. */
    for (j = 0; j < m; j++) {
        int u = edges[j].from;
        int v = edges[j].to;
        int w = edges[j].weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative-weight cycle reachable from source.\n");
            return 0;
        }
    }

    printf("Shortest distances from vertex %d:\n", source);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("To %d: Unreachable\n", i);
        else
            printf("To %d: %d\n", i, dist[i]);
    }

    return 0;
}
