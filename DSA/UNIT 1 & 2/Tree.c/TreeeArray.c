#include<stdio.h>
#include<stdlib.h>
#define max 10

typedef struct Node{
    int data;
    int used;
}node;

void init(node a[max])
{
    for(int i=0;i<max;i++)
        {
            a[i].used=0;
        }
}

void insert(node a[max])
{
    printf("Enter the rooot element; ");
    scanf("%d",&a[0].data);
    a[0].used=1;
    int ele,wish;

    do{

        printf("enter the element: ");
        scanf("%d",&ele);
        int p=0;
        while(p<max && a[p].used){
            if(ele < a[p].data)
                p=p*2+1;
            else
                p=2*p+2;
            
        }
        if(p>=max)
            printf("\nElement cant be inserted\n");
        else{
            a[p].data=ele;
            a[p].used=1;
        }
        printf("\nDo you wiah to add another ??:  ");
        scanf("%d",&wish);

    }while(wish);

}

void inorder(node* a, int r)
{
if(a[r].used)
{
inorder(a,2*r+1);
printf("%d ",a[r].data);
inorder(a,2*r+2);
}
}


int main()
{
    node a[max];
    init(a);
    insert(a);
    inorder(a,0);
    return 0;
}
