/*
i> Enqueue: addind from rear end
ii. Dequeue;  adding from front  end

*/

//This is Enqueue 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 5

typedef struct queue
{
    int a[n];
    int f;
    int r;
}Q;

void init(Q *q)
{
    q->f = -1;
    q->r = -1;
}

int empty(Q q)
{
    return (q.f == q.r && q.f == -1);
}

int isOneElement(Q q){

    return(q.f == q.r && q.f=0);
}

int isFull(Q q){
    return(q.r==n-1);
}

void Enqueue(Q *q,int ele){
    if(empty(*q)){
        q->f=q->r=0;
        q->a[q->r]=ele;

    }
    else if(isFull(*q)){
        printf("QUeue is Full and cant be inserted\n");
    }
    else
    q->a[++(q->r)]=ele;

}

void Dequeue(Q *q){
    if(empty(*q))
    {
        printf("\n Cant delete , Queue is empty \n ");
    }
    else if(isOneElement(*q))
    {
        
        q->r=q->f= -1;
    }
    else{
        (q->f)++;
    }

}

void display(Q q){
    int i;
    if(!empty(q)){
       for( i=q.f;i!=q.r;i++)
        {
            printf("%d ",q.a[i]);
       
        }
        
    }
    else{
         printf("The Queue is empty\n");
    }


}

int main()
{
    Q q;
    int ch;
    int ele;
    init(&q);
  
    do{
         printf("Enter your choice: \n");
        printf("1: Enqueue \n2: Dequeue \n3: display \n");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                    printf("\nEnter the element : ");
                    scanf("%d",&ele);
                    Enqueue(&q,ele);
                    break;

            case 2:Dequeue(&q);
                    break;

            case 3: display(q);
                    break;

        }
    }while(ch<4);

}