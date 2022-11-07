#include<stdio.h>
#include<stdlib.h>
int vartex,edge,t=0,topology[100],t_index=1,Y;
char map[100][100];
int index=1;
struct graph{
    int adj[100][100];
    int color[100];
    int discovery[100];
    int finish[100];
};
int mapping(char vname[])
{
    int i,j;
    for(i=1;i<=vartex;i++)
    {
        if(strcmp(map[i],vname)==0)
        {
            return i;
        }
    }
    strcpy(map[index++],vname);
    return index-1;
}
void dfs(struct graph *g,int start)
{
    int i,j,u;
    for(i=1;i<=vartex;i++)
    {
        g->color[i]=0;
        g->discovery[i]=0;
    }
    //for(i=1;i<=vartex;i++)
    i=start;
    while(1)
    {
        if(g->color[i]==0){
        dfs_visite(g,i);}
        //loop controll
        if(i<=vartex)
            i++;
        if(i>vartex)
            i=1;
        if(i==start)
            break;
    }
}
void dfs_visite(struct graph *g,int u)
{
    t=t+1;
    g->discovery[u]=t;
    g->color[u]=1;
    int v;
    for(v=1;v<=vartex;v++)
    {
        if(g->adj[u][v]==1 && g->color[v]==0)
        {
            g->color[v]=1;
            dfs_visite(g,v);
        }
    }
    g->color[u]=2;
    t=t+1;
    g->finish[u]=t;
    if(Y==1)
    topology[t_index++]=u;
    else
    printf("%s",map[u]);

}

void dfs_on_gt(struct graph *g)
{
    int i,j,u;
    for(i=1;i<=vartex;i++)
    {
        g->color[i]=0;
    }
    for(i=vartex;i>=1;i--)
    {
        if(g->color[topology[i]]==0){
            if(i!=vartex)
                printf("--");
        dfs_visite(g,topology[i]);}
    }
}

int main()
{
    int i,j,s,d,start;
     char source[100],dest[100],strt[100];
    struct graph *g=(struct graph*)malloc(sizeof(struct graph));
    struct graph *gt=(struct graph*)malloc(sizeof(struct graph));
    freopen("scc2.txt","r",stdin);
    scanf("%d %d",&vartex,&edge);
    for(i=1;i<=vartex;i++)
        for(j=1;j<=vartex;j++)
    {
        g->adj[i][j]=0;
        gt->adj[i][j]=0;
    }
    for(i=1;i<=edge;i++)
        {
        scanf("%s %s",&source,&dest);
        s=mapping(source);
        d=mapping(dest);
        g->adj[s][d]=1;
        gt->adj[d][s]=1;
        }
    Y=1;
    scanf("%s",strt);
    start=mapping(strt);
    dfs(g,start);
    t=0;
    Y=2;
    dfs_on_gt(gt);
    Y=1;

}
