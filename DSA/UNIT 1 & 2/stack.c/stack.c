#include<stdlib.h>
#include<stdio.h>
#define n 5

typedef struct stack
{
    int items[5];
    int top;
}stack;


void push(stack *p,int ele)
{
    if(p->top ==( n-1))
    printf("stack is full");
    else{

        p->top++;
        p->items[p->top]=ele;

    }
}

int pop(stack *p)
{
    if(p->top < 0)
    {
        printf("Empty stack");
    }
    else
    {
       int x=p->items[p->top];
        p->top--;
        return x;
    }
}

void display(stack *p)
{   
    if(p->top<=0)
    {
        printf("stack empty \n");

    }
    else
    {
        printf("[  ");
    for(int i=p->top; i>=0 ; i--)
    {
        printf("%d ,", p->items[i]);
    }
     printf("  ]");
    printf("\n");

    }
}



int main()
{
    int ch, ele,x,count=0;
     stack stk;
     stk.top=-1;
    do
    {
        printf("Enter the choice\n1: Push \n2: Pop \n3: Peek \n4: Display  \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: printf("Enter the element to be inserted : ");
                scanf("%d", &ele);
                push(&stk, ele);
                count++;
                break;

        case 2: x=pop(&stk);
                printf("popped element is : %d", x);
                count--;
                break;

        case 3: printf("the top most element is : %d", stk.items[stk.top]);
        
        case 4: display(&stk);
                printf("Number of elements is : %d",count);
                break;

        
        
        
        }
    } while (ch < 5);
}
