#include<stdio.h>
#include<string.h>
int v,e;
int color[100];
int dis[100];
int predecessor[100];
int graph[100][100];
int edge[100][100];
int finisht[100];
int start[100];
int t=0;
int print_path(int x ,int y)
{
    if(x==y)
        return 1;
    else if(predecessor[y]==0)
       return 0;

    else{
        print_path(x,predecessor[y]);
     }
}
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
    if(color[i]==0){
        dfs_visite(i);}
}

}
void dfs_visite(int u)
{
    t=t+1;
    if(start[u]==0){
           start[u]=t;
              }
    dis[u]=t;
    color[u]=1;
    int V;
    for(V=1;V<=v;V++)
    {
        if(graph[u][V]==1 && color[V]==0)
        {

            edge[u][V]=1;
            predecessor[V]=u;
            dfs_visite(V);
        }
    }
    color[u]=2;
    t=t+1;

    finisht[u]=t;
    ///-------------
    printf("%d ",u);
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
            edge[i][j]=0;
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
        for(j=1;j<=v;j++)
        {
         start[j]=0;
        }
    dfs();
///-----------*tree
/*
    printf("\nTree Edges are:\n");
    for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
        {
           if(edge[i][j]==1)
            printf("%d--->%d\n",i,j);

        }*/

///start time print
        /*for(j=1;j<=v;j++)
        {
         printf("%d ",start[j]);
        }*/
 ///--------------forward
 for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
        {
           if(edge[i][j]==0 && graph[i][j]==1)
            {
                if(start[i]<start[j]){
                    if(print_path(i,j)==1)
                    edge[i][j]=2;}
                if(start[i]>start[j]){
                    if(print_path(j,i)==1)
                    edge[i][j]=3;
                    else
                       edge[i][j]=4;
                    }
            }

        }
  ///--------------print edge type 1=tree 2=forwaed 3=back 4=cross
  printf("\n tree Edges are:\n");
     for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
        {
           if(edge[i][j]==1)
            printf("tree %d--->%d\n",i,j);
        }
printf("\n Forward Edges are:\n");
for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
        {
            if(edge[i][j]==2)
            printf("forward %d--->%d\n",i,j);
        }
printf("\n Backward Edges are:\n");
for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
        {
            if(edge[i][j]==3)
            printf("backward %d--->%d\n",i,j);
        }
printf("\n Cross Edges are:\n");
for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
        {
            if(edge[i][j]==4)
            printf("cross %d--->%d\n",i,j);
        }

}

