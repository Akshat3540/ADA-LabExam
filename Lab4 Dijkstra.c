#include <stdio.h>
#define INF 999
int n, i, j, u, v, cost[10][10], dist[10], vis[10] = {0}, min;

int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            scanf("%d", &cost[i][j]);
    scanf("%d", &u);
    for (i = 0; i < n; i++) 
        dist[i] = cost[u][i];
    dist[u] = 0; vis[u] = 1;
    for (i = 1; i < n; i++) {
        min = INF;
        for (j = 0; j < n; j++) 
            if (!vis[j] && dist[j] < min) min = dist[v = j];
        vis[v] = 1;
        for (j = 0; j < n; j++) 
            if (!vis[j] && dist[v] + cost[v][j] < dist[j])
            dist[j] = dist[v] + cost[v][j];
    }
    for (i = 0; i < n; i++) printf("From %d to %d = %d\n", u, i, dist[i]);
    return 0;
}
