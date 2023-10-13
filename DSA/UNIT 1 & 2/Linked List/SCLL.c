#include<stdlib.h>
#include<stdio.h>
typedef struct Node
{
    int data;
    struct Node *link;
}Node;

typedef struct list
{
    Node *tail;
}pl;

void init(pl *p)
{
    p->tail=NULL;
}

void insert_front(pl *p,int ele);
void insertlast(pl *p,int ele);
void deletefirst(pl *p);
void deletelast(pl *p);
void display(pl *p);
int main()
{
    int ch, ele;
    pl var;
    init(&var);
    do
    {
        printf("Enter the choice\n1: Insert Front \n2: Insert Last \n3: Delete First \n4: Delete Last \n5.Display  \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &ele);
            insert_front(&var, ele);
            break;

        case 2 :printf("Enter the element to be inserted : ");
            scanf("%d",&ele);
            insertlast(&var,ele);
            break;

        case 3:deletefirst(&var);
                break;

        case 4: deletelast(&var);
                break;

        case 5:
            display(&var);
            break;

        
        
        
        }
    } while (ch < 6 );
}
Node* createnode(int ele)
{
    Node *new = malloc(sizeof(Node));
    new->data = ele;
    new->link = NULL;
    return new;
}
void insert_front(pl *p,int ele)
{
	Node *new = createnode(ele);
	if(p->tail == NULL){
	p->tail = new;
    new->link=p->tail;
    return;
    }
	else    
	{
		new->link = p->tail->link;
		p->tail->link= new;
        return;
	}
}

void insertlast(pl *p,int ele)
{
    Node *new=createnode(ele);
    Node* q=p->tail;
    if(p->tail==NULL)
    {
        
        p->tail=new;
        new->link=p->tail;
        return;
    }
    else
    {
        new->link=p->tail->link;
        p->tail->link=new;
        p->tail=p->tail->link;
        return;
    
    }
}

void deletefirst(pl *p)
{
    Node *q=p->tail->link;
    if(p->tail==NULL)
    {
        printf("Nothing to ""Delete""");
        return ;
    }
    
    else if (q == p->tail)
    {
        free(q);
        p->tail=NULL;
        return;
    }
    
    else
    {  
        p->tail->link=q->link;
        free(q);
        return;

    }

}

void deletelast(pl *p)
{
    Node *q=p->tail->link;
    if(p->tail==NULL)
    {
        printf("Nothing to ""Delete""");
        return ;
    }
    
    else if (q == p->tail)
    {
        free(q);
        p->tail=NULL;
        return;
    }

    else
    {
        Node* temp=p->tail;
        while(q->link != p->tail)
        {
            q=q->link;
        }
        q->link=p->tail->link;
        p->tail=q;
        free(temp);
    }

}

void display(pl *p)
{
    if(p->tail==NULL){
        printf("Empty list\n");
        return ;
    }
        Node *q;
        q=p->tail->link;

        while(q!=p->tail)
        {
            printf("%d  ",q->data);
            q=q->link;
        }
        printf("%d\n",q->data);

}
