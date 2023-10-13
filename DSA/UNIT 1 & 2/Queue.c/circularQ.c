#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct Node
{
    int a[max];
    int f;
    int r;
}cn;

void init(cn *q)
{
    q->f=-1;
    q->r=-1;
}

int empty(cn *q)
{
    return ( q->f==-1);
}

int full(cn *q){
    return ((q->r+1)%max == q->f);      
}

void enqueue(cn *q,int ele)
{
    if(full(q)){
        printf("FULLLLLL!!!!!!!");
        return ;
    }
    else{
        if(empty(q));
        q->f=0;
    }
    q->r=(q->r +1)%max ;
    q->a[q->r]= ele;

}

void dequeue(cn *q )
{
    if(empty(q)){
    printf("Cant delete it in empty");
    return; }

    if(q->f==q->r)
    {
        q->f=-1;
        q->r=-1;
    }
    else{
        q->f=(q->f+1)%max;
    }
}

void display(cn *q)
{
    int i;
    if(empty(q)){
        printf("Empty");
        return;}
    else{
    printf("Circular queue: ");
    for( i=q->f;i!=q->r; i=(i+1)%max)
    {
        printf("%d ,",q->a[i]);
    }
    }
    printf(" %d",q->a[i]);
    printf("\n");
}


int main()
{
    cn q;
    int ch,ele;
    init(&q);
    do
    {
        printf(" 1. Enqueue \n2. Dequeue \n3. Display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the element you want toInsert: ");
                scanf("%d",&ele);   
                    enqueue(&q,ele);
                    break;
            case 2: dequeue(&q);
                    break;
            case 3: display(&q);
            break;
        }
    } while (ch < 4);
    return 0;
    

}