#include <stdio.h>
#include <limits.h>
#define V 5
#define INF INT_MAX
void printSolution(int dist[][V]) {
    printf("The shortest distances b/w every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
void floydWarshall(int graph[][V]) {
    int dist[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printSolution(dist);
}
int main() {
    int graph[V][V] = {
        {0,   10,  INF, 30, INF},
        {10, 0,   5,  INF, 20},
        {INF, 5, 0,   15, 10},
        {30, INF, 15, 0, INF},
		{INF, 20, 10, INF, 0}
    };
    floydWarshall(graph);
    return 0;
}
