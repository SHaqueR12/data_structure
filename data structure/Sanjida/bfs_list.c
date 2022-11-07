#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int v,e;
struct node{
    int data;
    struct node *next;
};
struct node *list[10000];
void initializer_list()
{
   int i;
   for(i=0;i<=10;i++)
        list[i]=NULL;
}
void insert(int m,int n)
{
  struct node *newnode=malloc(sizeof(struct node));
  newnode->data=n;
  newnode->next=NULL;

  if(list[m]==NULL)
  {
      list[m]=newnode;
  }
  else
  {
    struct node *temp=list[m];
    while(temp->next)
    {
        temp=temp->next;

    }
    temp->next=newnode;
  }

}
void print()
{
    int i;
    for(i=1;i<=v;i++)
    {
        printf("V[%d]- ",i);
        struct node *temp=list[i];
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;

    }
    printf("\n");
    }
}
///********************************************************

int color[100];
int distance[100];
int predecessor[100];
int index=1;
char map[100][100];
int mapping(char vname[])
{
    int i,j;
    for(i=1;i<=v;i++)
    {
        if(strcmp(map[i],vname)==0)
        {
            return i;
        }
    }
    strcpy(map[index++],vname);
    return index-1;
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
    int Q[100],head=0,tail=0,k=0;
    Q[head++]=s;

    while(head!=tail)
    {
      u=Q[tail++];
      printf("%s ",map[u]);
      //printf("%d ",u);
          struct node *temp=list[u];
            while(temp)
            {
            i=temp->data;
            if(color[i]==0)
          {
              color[i]=1;
              distance[i]=distance[u]+1;
              predecessor[i]=u;
              Q[head++]=i;
          }
            temp=temp->next;
            }
      color[u]=2;
    }
}
int main()
{
    initializer_list();
    int i,j,s,d;
    char source[100],dest[100];
    freopen("bfs.txt","r",stdin);
    scanf("%d %d",&v,&e);
    for(i=1;i<=e;i++)
    {
        scanf("%s %s",&source,&dest);
        s=mapping(source);
        d=mapping(dest);
        insert(s,d);
        insert(d,s);

    }

    ///==================print graph
    print();
   int start=1;
   printf("\nBfs\n");
   bfs(start);
   printf("\n");

}
