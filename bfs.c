#include<stdio.h>
#include<string.h>
int v,e;
int color[100];
int distance[100];
int predecessor[100];
int graph[100][100];

void print_path(int s ,int vv)
{
    if(vv==s)
        printf("%d\n",s);
    else if(predecessor[vv]==0)
       printf("No path from %d to %d exist",s,vv);

    else{
        print_path(s,predecessor[vv]);
     printf("%d\n",vv);}
}
void bfs(int s)
{
    int i,j,u;
    for(i=1;i<=v;i++)
    {
        color[i]=0;
        predecessor[i]=0;
       distance[i]=1000;
    }
     color[s]=1;
     distance[s]=0;
      predecessor[s]=0;
    int Q[100],head=0,tail=0;
    Q[head++]=s;

    while(head!=tail)
    {
      u=Q[tail++];
      //tail++;
      printf("%d ",u);
      for(i=1;i<=v;i++)
      {
          if(graph[u][i]==1 && color[i]==0)
          {
              color[i]=1;
              distance[i]=distance[u]+1;
              predecessor[i]=u;
              Q[head++]=i;
               //head++;
          }

      }
      color[u]=2;
    }
}
int main()
{
    int i,j,s,d;
    freopen("bfs.txt","r",stdin);
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
   int start=1;
  bfs(start);
  print_path(2,3);
}
