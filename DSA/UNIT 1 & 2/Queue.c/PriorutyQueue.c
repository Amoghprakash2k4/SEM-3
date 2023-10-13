#include<stdio.h>
#include<stdlib.h>
#define max 5

typedef struct node 
{
        int a[max];
        int f;
        int r;
}node;

void init(node *q)
{
        q->f=-1;
        q->r=-1;
}

int isfull(node *q){
        return( q->r ==max-1);
}

int isempty(node *q)
{
        return (q->f==q->r && q->f== -1);
}

void Enqueue(node *q, int ele)
{
        if(isfull(q)){
                printf("FUll  Queue!!::::\n");}

        else{
        int j=q->r;
        while(j<=0 && ele <q->a[j])
        {
                q->a[j+1]= q->a[j];
                j--;
        }
        q->a[j+1]= ele;
        ++(q->r);}
        return;
}
void Dequeue(node *q){
        if(isempty(q))
                printf("Empty Queue:\n");
                return;
        ++(q->f);
        return;
}

void display(node *q){
        if(isempty(q)){
                printf("Empty::\n");

        }
        else{
                int i=q->f;
                for(i=q->f; i<= q->r;i++)
                {
                        printf("%d",q->a[i]);
                }
        }
        return;
}

int main()
{
    int ch;
    int ele;
    node q;
    init(&q);
  
    do{
         printf("Enter your choice: \n");
        printf("1:  \n2: Dequeue \n3: display \n");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                    printf("\nEnter the element : ");
                    scanf("%d",&ele);
                    Enqueue(&q,ele);
                    break;

            case 2:Dequeue(&q);
                    break;

            case 3: display(&q);
                    break;

        }
    }while(ch<4);

}