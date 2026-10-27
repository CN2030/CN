/* Experiment 3: Dijkstra shortest paths.
   Enter 0 for no edge between different vertices.
   This version treats the graph as undirected and requires non-negative weights.
*/
#include <stdio.h>

#define MAX 10
#define INF 999999

int main(void) {
    int cost[MAX][MAX], dist[MAX], visited[MAX];
    int n, source, i, j, count, min, u;

    printf("Enter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter cost matrix (%d x %d; 0 means no edge):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (scanf("%d", &cost[i][j]) != 1 || cost[i][j] < 0) {
                printf("Invalid cost. Use non-negative values.\n");
                return 1;
            }
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex (0-%d): ", n - 1);
    if (scanf("%d", &source) != 1 || source < 0 || source >= n) {
        printf("Invalid source vertex.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[source] = 0;

    for (count = 0; count < n; count++) {
        min = INF;
        u = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && cost[u][j] != INF &&
                dist[u] + cost[u][j] < dist[j]) {
                dist[j] = dist[u] + cost[u][j];
            }
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
