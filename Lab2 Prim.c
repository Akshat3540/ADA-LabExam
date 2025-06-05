#include <stdio.h>
int n, cost[20][20],  source, visited[20], ne=1, min, min_cost=0, i, j, a, b, u, v;

int main(){
    scanf("%d", &n);
    for(i=1;i<=n;i++) 
        for(j=1;j<=n;j++) 
            scanf("%d", &cost[i][j]);
    scanf("%d", &source);
    visited[source]=1;
    printf("Minimum cost Spanning tree is\n");
    while(ne<n){
        min=999;
        for(i=1;i<=n;i++) 
            for(j=1;j<=n;j++)
                if(cost[i][j]<min && visited[i] && !visited[j])
                    min=cost[i][j], a=u=i, b=v=j;
        printf("Edge %d\t(%d -> %d) = %d\n", ne++, a, b, min);
        min_cost+=min; visited[b]=1; 
        cost[a][b]=cost[b][a]=999;
    }
    printf("Minimum cost = %d\n", min_cost);
    return 0;
}
