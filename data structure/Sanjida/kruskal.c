#include<stdio.h>
#include<string.h>
int u[100],v[100],w[100],parent[100],vartex,e;
char map[100][100];
int index=1;
int findset(int x){
    if(parent[x]!=x)
        parent[x]=findset(parent[x]);
    return parent[x];
}
void U(int x,int y)
{
    parent[x]=y;
}
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
void sort(int e)
{ int temp;
     for(int i=1;i<=e;i++)
        for(int j=1;j<=e;j++)
     {
         if(w[i]<w[j])
         {
             temp=w[i];
             w[i]=w[j];
             w[j]=temp;

             temp=u[i];
             u[i]=u[j];
             u[j]=temp;

             temp=v[i];
             v[i]=v[j];
             v[j]=temp;

         }
     }

}
int main()
{
    int s,d,wi,i,j,mst=0;
    char source[100],dest[100];
    freopen("kruskal.txt","r",stdin);
    scanf("%d %d",&vartex,&e);
    ///make set
    for(i=1;i<=vartex;i++)
        parent[i]=i;
    for(i=1;i<=e;i++)
    {
        scanf("%s %s %d",&source,&dest,&wi);
        s=mapping(source);
        d=mapping(dest);
        u[i]=s;
        v[i]=d;
        w[i]=wi;
    }
    sort(e);


    for(i=1;i<=e;i++)
    {
        if(findset(u[i])!=findset(v[i]))
        {    printf("%s-%s %d\n",map[u[i]],map[v[i]],w[i]);
            U(findset(u[i]),findset(v[i]));
               mst=mst+w[i];
        }
    }
    printf("MST=%d",mst);
}
