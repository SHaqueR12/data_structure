#include<stdio.h>
#include<string.h>
int discovery[100],parent[100],vrtx;
int U[100],V[100],W[100];
char map[100][100];
int index=1;
int mapping(char vname[])
{
    int i,j;
    for(i=1;i<=vrtx;i++)
    {
        if(strcmp(map[i],vname)==0)
        {
            return i;
        }
    }
    strcpy(map[index++],vname);
    return index-1;
}
///****************relax
void relax(int u ,int v,int w)
{
    if(discovery[v]>discovery[u]+w)
    {
        discovery[v]=discovery[u]+w;
        parent[v]=u;
    }
}

int bellmanford(int edge)
{
    int i,j;
    for(i=1;i<=edge;i++)
        {
            if(discovery[V[i]]>discovery[U[i]]+W[i])
             return 1;//false
        }

    return 0;//true

}
int main()
{
  int s,d,wi,i,j,e,vartex;
    char source[100],dest[100];
    freopen("bellmanmap.txt","r",stdin);
    scanf("%d %d",&vartex,&e);
    vrtx=vartex;

    ///scan graph
    for(i=1;i<=e;i++)
    {
        //scanf("%d %d %d",&s,&d,&wi);
        scanf("%s %s %d",&source,&dest,&wi);
        s=mapping(source);
        d=mapping(dest);
        U[i]=s;
        V[i]=d;
        W[i]=wi;
    }

///-----------initialize
    for(i=1;i<=vartex;i++)
    {
        discovery[i]=999;
        parent[i]=0;
    }
    ///scan a source to start,now its 1 for try---initialize
    scanf("%s",&source);
    s=mapping(source);
    discovery[s]=0;

for(i=1;i<vartex;i++)
    for(j=1;j<=e;j++)
        {
             relax(U[j],V[j],W[j]);
        }

int y=bellmanford(e);
if(y==0)
    printf("Negative cycle exist\n");
else
    printf("No Negative cycle exist\m");
}

