#include<stdio.h>
#include<stdlib.h>
int discovery[100],parent[100],vrtx,graph[100][100],q[100];
///mapping------->
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
}///<--------mapping
///     extract_min---->

int extract_min()
{
    int i,j,min=9999,u;
    for(i=1;i<=vrtx;i++)
    {
        if(discovery[i]<min && q[i]==0){
        min=discovery[i];
        u=i;}
    }
    return u;
}




///<----------------------------extract_min

///    relax--------->
void relax(int u ,int v,int w)
{
    if(discovery[v]>discovery[u]+w)
    {
        discovery[v]=discovery[u]+w;
        parent[v]=u;
    }
}///<----relax

int main()
{
  int s,d,wi,i,j,e,vartex;
    char source[100],dest[100];
    freopen("dukstra.txt","r",stdin);
    scanf("%d %d",&vartex,&e);
    vrtx=vartex;
    for(i=1;i<=vartex;i++)
        for(j=1;j<=vartex;j++)
    {
        graph[i][j]=0;
    }
    ///scan graph
    for(i=1;i<=e;i++)
    {
        scanf("%s %s %d",&source,&dest,&wi);
        s=mapping(source);
        d=mapping(dest);
        graph[s][d]=wi;
    }

///-----------initialize
    for(i=1;i<=vartex;i++)
    {
        discovery[i]=999;
        q[i]=0;///Q--taken
        parent[i]=0;
    }
    scanf("%s",&source);//scan a source to start,
    s=mapping(source);
    discovery[s]=0;
            ///<---initialize
int S[100];
int x=1;
while(x<=vartex)
{
    int u=extract_min();
    q[u]=1;
    S[i]=u;
    i++;
    for(j=1;j<=vartex;j++)
        {
            if(graph[u][j]!=0 && q[j]==0){

             relax(u,j,graph[u][j]);

            }
        }
    x++;
}

 for(j=1;j<=vartex;j++)
    printf("%d ",discovery[j]);
}
