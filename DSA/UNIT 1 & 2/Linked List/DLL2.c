#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *llink;
    struct Node* rlink;

}Node;

typedef struct pl
{
    Node* head;
}pl;

void init(pl *p);
Node* createnode(int ele);
void insertfront(pl *p,int ele);
void insertlast(pl *p,int ele);
void deletefirst(pl *p);
void insertpos(pl *p,int ele,int pos);
void display(pl *p);


int main()
{
    int ch,ele,pos;
    pl var;
    init(&var);
    do
    {
        printf("1: Insert front \n2: Insert last \n3: Delete Last \n4: Insert at a pos \n5: display\n :)--> Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element: ");
                    scanf("%d",&ele);
                    printf("\n");
                    insertfront(&var,ele);
                    break;

            case 2:  printf("Enter the element: ");
                    scanf("%d",&ele);
                    printf("\n");
                    insertlast(&var,ele);
                    break;
            
            case 3: deletefirst(&var);
                    break;
            
            case 4: printf("Enter the element: ");
                    scanf("%d",&ele);
                    printf("Enter the position: ");
                    scanf("%d",&pos);
                    printf("\n");
                    insertpos(&var,ele,pos);
                    break;

            case 5: display(&var);
                    break;

            
        }

    } while(ch<6);
}
void init(pl *p)
{
    p->head=NULL;
}

Node* createnode(int ele)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=ele;
    temp->llink=NULL;
    temp->rlink =NULL;
    return temp;


}    

void insertfront(pl *p,int ele)
{
    Node *new=createnode(ele);
    if(p->head==NULL)
    {
        p->head = new;
    }
    else
    {
        new->rlink=p->head;
        p->head=new;

    }
}
 
void insertlast(pl *p,int ele)
{
    Node *new=createnode(ele);
    if(p->head==NULL)
    {
        p->head = new; 
    }
    else
    {
        Node *q=p->head;
        while(q->rlink!=NULL)
        {
            q = q -> rlink;

        }
        q-> rlink= new;
        new->llink=q;
    }
}


void deletefirst(pl *p)
{
    Node* q=p->head;
    if(p->head==NULL)
         printf("Empty List");

    else if(p->head->rlink==NULL)
    {
        p->head=NULL;
        free(q);
    }
    else
    {
        p->head=p->head->rlink;
        p->head->llink=NULL;
        free(q);
    }
}

void insertpos(pl *p,int ele,int pos)
{
    Node* new=createnode(ele);
    if(p->head == NULL)
    {
        printf("since the list is empty it will be in pos:EOL ");
        p->head= new;
    }
    else
    {
        Node* current=p->head;
        Node* prev=p->head;
        int count=1;
        while(current->rlink!=NULL && count!=pos)
        {   
           prev=current; 
           current=current->rlink; 
           count++;
        }
        new->rlink = current;
        new->llink = prev;
        prev->rlink = new;
        current -> llink = new;


    }
}

void display(pl *p)
{
    Node *q=p->head;
    if(!q)
        printf("Empty list\n");
                    
    else
    {
        while(q)
        {
        printf("%d  ",q->data);
        q=q->rlink;
        }

    }
    printf("\n");
}

