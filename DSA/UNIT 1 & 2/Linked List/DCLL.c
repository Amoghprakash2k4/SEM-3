#include<stdlib.h>
#include<stdio.h>

typedef struct Node 
{
    int data;
    struct Node *llink;
    struct Node *rlink;
}Node;

typedef struct pl
{
    int info;
    Node* head;
}pl;

void init(pl *p)
{
    p->head=NULL;
}

Node  *createnode(int ele);
void insertfront(pl *p,int ele);
void insertlast(pl *p,int ele);
void deletefirst(pl *p);
void display(pl *p);

int main()
{
    int ele,ch,pos,info;
    pl var;
    init(&var);
    do
    {
        printf("\n1: Insert front \n2: Insert Last \n3: Delete First \n9: Display \nEnter your choice:-> ");
        scanf("%d",&ch);
        printf("\n");
        switch (ch)
        {

        case 1: printf("Enter the elemnt: ");
                scanf("%d",&ele);
                insertfront(&var,ele);
                printf("\n");
                break;
            
        case 2: printf("Enter the elemnt: ");
                scanf("%d",&ele);
                insertlast(&var,ele);
                printf("\n");
                break;
        case 3: deletefirst(&var);
                break;

        case 9: display(&var);
                break;
       
        }
    } while (ch<10);
    
}
Node  *createnode(int ele)
{
    Node *new=(Node*)malloc(sizeof(Node));
    new->data=ele;
    new->llink=NULL;
    new->rlink=NULL;
    return new;

}

void insertfront(pl *p,int ele)
{
    Node *new=createnode(ele);
    if(p->head==NULL)
    {
        p->head=new;
        new->rlink=p->head;
        new->llink=new;
        
    }
    else
    {
       new->rlink = p->head;
       new->llink = p->head->llink;
       p->head->llink->rlink = new;
       p->head->llink = new;
       p->head = new;
        
     }
}

void insertlast(pl *p,int ele)
{
    Node *new=createnode(ele);
    if(p->head==NULL)
    {
        p->head=     new;
        new->rlink=p->head;
        new->llink=new;
   
    }
    else
    {
        new->llink=p->head->llink;
        new->rlink= p->head;
        p->head->llink->rlink=new;
        p->head->llink = new;
        
        
       


    }

}

void deletefirst(pl *p)
{
    if(p->head==NULL)
    printf("Nothing to Print");

    else if (p->head==p->head->rlink)
    {
        Node *q=p->head;
        free(q);
        p->head=NULL;
    }
    else
    {
       Node *q=p->head;
       Node *w=p->head;
       q=q->rlink;
       q->llink= p->head->llink;
       p->head->llink->rlink= q;
       p->head = p->head->rlink;
       free(w);
       

    }
}

void display(pl *p)
{
    if(p->head==NULL)
    {
        printf("Nothing to print #$^@");
        return;
    }
    
        Node* q=p->head;
        do
        {
            printf("%d ",q->data);
            q=q->rlink;
        }while(q != p->head);
        printf("\n");
        
       
        
}