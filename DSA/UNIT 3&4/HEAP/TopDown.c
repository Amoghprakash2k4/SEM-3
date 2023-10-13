#include<stdio.h>
#include<stdlib.h>

void TopDown(int h[],int ele,int *count)
{
    int c= *count;
    h[c]=ele;
    int p= (c-1)/2;
    while( c > 0 && ele >=h[p])
    {
        h[c]=h[p];
        c=p;
        p=(c-1)/2;
    }
    h[c]=ele;
    *count=*count+1;
}

void display(int h[],int n)
{
    
    for(int i=0;i<n;i++)
    {
        printf("%d ",h[i]);
    }
}


int main()
{
    int n=6;
    int count=0;
    int h[n];
    int ele;
    printf("Enter the elements: ");
    for(int i=1;i<=6;i++)
    {
        scanf("%d",&ele);
         TopDown(h,ele,&count);
        
    }
   
    display(h,n);
    
}