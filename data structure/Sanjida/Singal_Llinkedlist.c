#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *next;
};
void print(struct node *p){
while(p!=NULL){
        printf("%d ",p->data);
        p= p->next;}}
void reverselinkedlist(struct node *head){
struct node *pre=NULL;
struct node *selectnode=head;
struct node *nextt=NULL;
while(selectnode!=NULL){
    nextt=selectnode->next;
    selectnode->next=pre;
    pre=selectnode;
    selectnode=nextt;
}



void arecurrsion(struct node *test){
if(test->next!=NULL){
    return ;}
else
{
    arecurrsion(test->next);

}
printf("%d",test->data);
}
head=pre;
print(head);
}



struct node *insertNewHead(struct node *oldhead,int newdata){
struct node *newhead=(struct node*)malloc(sizeof(struct node));
newhead->next=oldhead;
newhead->data=newdata;
return newhead;
};
struct node *insertByIndex(struct node *head,int newdata,int index){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
struct node *selectnode=head;
int i=0;
while(i!=index-1){
    selectnode=selectnode->next;
    i++;
}
newnode->data=newdata;
newnode->next=selectnode->next;
selectnode->next=newnode;
};
struct node *insertAtEnd(struct node *head,int newdata){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
struct node *selectnode=head;
while(selectnode->next!=NULL){
    selectnode=selectnode->next;
}
newnode->data=newdata;
newnode->next=NULL;
selectnode->next=newnode;
};
struct node *insertAfterdata(struct node *head,int positiondata,int newdata){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
struct node *selectnode=head;
while(selectnode->data!=positiondata){
    selectnode=selectnode->next;
}
newnode->data=newdata;
newnode->next=selectnode->next;
selectnode->next=newnode;
};
int main()
{
    struct node *a=NULL;
    struct node *b=NULL;
    struct node *c=NULL;

    a=(struct node*)malloc(sizeof(struct node));
    b=(struct node*)malloc(sizeof(struct node));
    c=(struct node*)malloc(sizeof(struct node));

    a->data=10;
    b->data=20;
    c->data=30;
    a->next=b;
    b->next=c;
    c->next=NULL;

//   a=insertAtHead(a,5);
//     insertByIndex(a,15,2);
//     insertAtEnd(a,50);
 //    insertAfterdata(a,20,25);
 //      reverselinkedlist(a);//print included
  // print(a);
   arecurrsion(a);
}
