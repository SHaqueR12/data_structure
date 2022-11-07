#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head, *newnode, *temp,*c,*p,*bef,*aft,*temp1,*temp2,*tail;
///insert
void insert(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=0;
    newnode->prev=0;
    if(head==0)
    {
        head=temp=newnode;
    }

    else
    {
        temp->next=newnode;
        newnode->prev=temp;
        temp=temp->next;
    }
}

int search(int a)
{
    c=head;
    temp1=0;
    int k=0;
    while(c!=0)
    {
        if(c->data==a)
        {
            k=1;
            temp1=c;
            return 1;
            break;
        }
        c=c->next;
    }
       return 0;
}

viewnode()
{
    p=head;
    while(p!=0)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
r_viewnode()
{
    tail=temp;
    while(tail!=0)
    {
        printf("%d ",tail->data);
        tail=tail->prev;
    }
}


///-----Insert at any position

void inst(int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=0;
    newnode->prev=0;
    if(head==0)
    {
        head=temp1=temp=newnode;
    }

    else
    {   if(temp1==0)
            {
                printf("\nInvalid position to insert\n");
            }
      else if(temp1->next!=0){
        temp2=temp1->next;
        newnode->prev=temp1;
        newnode->next=temp1->next;
        temp1->next=newnode;
        temp2->prev=newnode;}
        else{
               temp1->next=newnode;
               newnode->prev=temp1;
               temp=newnode;
            }
    }
}

sp(int l,int m){
 search(l);
 inst(m);

}


///delete
 void dlt(int x){
    int k=search(x);
if(k==1)
    {
        c=temp1;
    bef=c->prev;
    aft=c->next;


       if(bef==0)
            {
            aft->prev=0;
            free(c);
            head=aft;
            }
        else if(aft==0)
            {
            bef->next=0;
            temp=bef;
            free(c);
            }

        else{
            bef->next=c->next;
            aft->prev=c->prev;
            free(c);
            temp=aft;
            }
    }
}

///main
int main()
{
    struct node *newnode;
    int i, a, b, c, n,z=0,kk,key,comand;
    head=0;
    while(scanf("%d",&n)==1)
    {
        insert(n);
    }
    printf("the list is: ");
    viewnode();

 printf("\n press any key to oprtate\n");
 printf("\n 1)Search 2)inser\n");
 printf("\n 3)delete 4)insert after a value\n");
 printf("\n 5)reverse view 6)stop operation\n");
getchar();
while(1)
{
    printf("\nenter command: ");
    scanf("%d",&comand);
    if(comand==1)
        {     printf("\nEnter the value searching for: ");
            scanf("%d",&key);
                kk=search(key);
            if(kk==1)
            printf("\n%d Found",key);
            if(kk==0)
            printf("\n%d Not found",key);

       }
       if(comand==2)
        {printf("\nEnter the value to insert: ");
            scanf("%d",&n);
             insert(n);
             printf("\nUpdated list :");
            viewnode();
        }
       if(comand==3)
        {   printf("\nEnter the value want to delete: ");
            scanf("%d",&n);
             dlt(n);
             printf("\nUpdated list :");
            viewnode();
        }
       if(comand==4)
        {   printf("\nGive the value after which u want to inser & insert  value: ");
            scanf("%d",&n);
            scanf("%d",&key);
             sp(n,key);
             printf("\nUpdated list :");
            viewnode();
        }

        if(comand==5)
        {
             printf("\nUpdated list :");
            r_viewnode();
        }
        if(comand==6)
        {
             break;
        }

}

}
// 1 2 3 4 5 6 7 8 9 ^z

