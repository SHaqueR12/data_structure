#include<stdio.h>
#include<string.h>
int u[100],v[100],parent[100],vartex,e;
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

int findset(int x){
    if(parent[x]!=x)
        parent[x]=findset(parent[x]);
    return parent[x];
}
void U(int x,int y)
{
    parent[x]=y;
}

int same_set(int u, int v)
{
     if(findset(u)==findset(v))
        return 1;
     else
        return 0;
}

int main()
{
    int s,d,i,j;
    char source[100],dest[100];
    freopen("disjoint.txt","r",stdin);
    scanf("%d %d",&vartex,&e);
//vartex scan
   for(i=1;i<=vartex;i++)
   {
       scanf("%s",&source);
       mapping(source);
   }
    ///make set   book=>1-2
    for(i=1;i<=vartex;i++)
        parent[i]=i;
//edge scan
    for(i=1;i<=e;i++)
    {
        scanf("%s %s",&source,&dest);
        s=mapping(source);
        d=mapping(dest);
        u[i]=s;
        v[i]=d;

    }
///book=>3-5
    for(i=1;i<=e;i++)
    {
        if(findset(u[i])!=findset(v[i]))
        {
            U(findset(u[i]),findset(v[i]));

        }
    }
///scan two vartex to check if they r in same set or not
/*
  scanf("%s %s",&source,&dest);
    s=mapping(source);
    d=mapping(dest);
  int y;
  y=same_set(s,d);
  if(y==1)
    printf("%s & %s belongs to same set\n",source,dest);
  else
    printf("%s & %s does not belong to same set\n",source,dest);
    */

//print set
    for(i=1;i<index;i++)
    {   int b=0;

        for(j=1;j<index;j++)
        {

           if(findset(j)==i){
                if(b==0){
                 printf("{");
                 b=1;}
                printf("%s",map[j]);}
        }
        if(b==1)
         printf("} ");

    }
}

