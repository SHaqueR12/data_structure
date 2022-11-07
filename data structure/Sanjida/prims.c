#include<stdio.h>
#include<string.h>
int vartex,edge,graph[100][100];
int key[100],q[100],parent[100];
char map[100][100];
int index=1;
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

int findmin()
{
    int i,j,min=999,u;
    for(i=1;i<=vartex;i++)
    {
        if(key[i]<min && q[i]==0){
        min=key[i];
        u=i;}
    }
    return u;
}
void prims()
{
    int i,j,u;
    for(i=1;i<=vartex;i++)
    {
      key[i]=999;//edge weight q //index is the vartex & value is min edge to reach the vartex
      q[i]=0;//vartex q visited or not(0=not visited 0=visited
    }
 key[1]=0;
parent[1]=-1;
 int x=1;
 while(x<=vartex)
    {   u=findmin();
        q[u]=1;
        for(int v=1;v<=vartex;v++)
        {
            if(graph[u][v]!=0 && q[v]==0 && graph[u][v]<key[v]){
            key[v]=graph[u][v];
            parent[v]=u;}
        }

       x++;
    }
}
int main()
{
    int i,j,s,d,w,mst=0;
    char source[100],dest[100];
    freopen("prims.txt","r",stdin);
    scanf("%d %d",&vartex,&edge);
    for(i=1;i<=vartex;i++)
         for(j=1;j<=vartex;j++)
        {
            graph[i][j]=0;
        }

    for(i=1;i<=edge;i++){
        scanf("%s %s %d",&source,&dest,&w);
        s=mapping(source);
        d=mapping(dest);
        graph[s][d]=w;
        graph[d][s]=w;
    }

    prims();

printf("edge \tweight\n\n");
    for(i=1;i<=vartex;i++)
    {
        if(key[i]>0)
            printf("%s-%s\t%d\n",map[parent[i]],map[i],key[i]);
        mst=mst+key[i];
    }
    printf("\nMST = %d\n",mst);
}
