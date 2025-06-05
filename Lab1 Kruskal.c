#include <stdio.h>
int p[20] = {0}, ne=1, cost[20][20], n, i, j, a, b, u, v, min, min_cost=0;
int find(int x){
    while(p[x]) x=p[x];
    return x;
}
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++) 
            scanf("%d",&cost[i][j]);
    printf("The edges of Spanning tree are\n");
    while(ne<n){
        min=999;
        for(i=1;i<=n;i++) 
            for(j=1;j<=n;j++)
                if(cost[i][j]<min) min=cost[i][j], a=u=i, b=v=j;
        u=find(u); v=find(v);
        if(u!=v){
            printf("Edge %d\t(%d -> %d) = %d\n",ne++,a,b,min);
            min_cost+=min; p[v]=u;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("Minimum cost = %d\n",min_cost);
    return 0;
}
