#include<stdio.h>
#include<string.h>
int v,e;
int color[100];
int dis[100];
int predecessor[100];
int graph[100][100];
int finisht[100];
int t=0;
void dfs()
{
    int i,j,u;
    for(i=1;i<=v;i++)
    {
        color[i]=0;
        predecessor[i]=0;
    }
    t=0;
for(i=1;i<=v;i++)
{
    if(color[i]==0)
        dfs_visite(i);
}

}
void dfs_visite(int u)
{
    t=t+1;
    dis[u]=t;
    color[u]=1;
    int V;
    for(V=1;V<=v;V++)
    {
        if(graph[u][V]==1 && color[V]==0)
        {
            predecessor[V]=u;
            dfs_visite(V);
        }
    }
    color[u]=2;
    t=t+1;
    finisht[u]=t;
    ///-------------
    printf("%d",u);
}
int main()
{
    int i,j,s,d;
    freopen("dfs.txt","r",stdin);
    scanf("%d %d",&v,&e);
    for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
        {
            graph[i][j]=0;
        }

    for(i=1;i<=e;i++)
    {
        scanf("%d %d",&s,&d);
        graph[s][d]=1;
        //graph[d][s]=1;
    }

    ///==================
    /*
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++)
        {
            printf("%d",graph[i][j]);
        }
        printf("\n");
        }
*/
    dfs();
}
/*
13 19
1 2
1 6
2 3
3 5
3 4
4 2
4 5
6 7
7 8
8 6
8 9
9 4
9 10
7 12
8 11
11 12
11 13
13 8
13 9
*/
