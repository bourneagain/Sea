#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert(struct node **,int);
void makecircular(struct node **,int ,int);
void segregate(struct node **);
void printlist(struct node *p)
{
    int n=0;
    while(p!=NULL)
    {
        printf(" %d ",p->data);
        p=p->next;
        n++;
    }
}
int main()
{
    struct node *p=(struct node * )malloc(sizeof(struct node));
    p=NULL;
    insert(&p,22);
    insert(&p,11);
    insert(&p,2);
    insert(&p,33);
    insert(&p,21);
    insert(&p,32);
    printlist(p);
    segregate(&p);
    printf("\n\n\n\n");
    printlist(p);
    return 0;
}
void insert(struct node **p,int num)
{
    struct node *r,*s;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    if(*p==NULL)
    {
        *p=temp;
        return;
    }
    r=*p;
    while(r->next!=NULL)
        r=r->next;
    r->next=temp;
}
void segregate(struct node **p)
{
    struct node *s,*a=NULL,*b=NULL,*c,*t;
    t=*p;
    while(t!=NULL)
    {
        if((t->data)%2==0)
        {
            if(a==NULL)
            {
                a=(struct node*)malloc(sizeof(struct node));
                a->data=t->data;
                s=a;
            }
            else
            {
                a->next=(struct node*)malloc(sizeof(struct node));
                a->next->data=t->data;
                a=a->next;
            }
            t=t->next;
        }
        else
        {   if(b==NULL){
                b=(struct node*)malloc(sizeof(struct node));
                b->data=t->data;
                c=b;
            } else {
                b->next=(struct node*)malloc(sizeof(struct node));
                b->next->data=t->data;
                b=b->next;
            }
            t=t->next;
        }
    }
    a->next=c;
    b->next=t;
    *p=s;
    return;
}

