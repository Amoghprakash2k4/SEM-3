#include<stdio.h>
#include<stdlib.h>

void BottomUp(int h[],int n)
{
    int k,v,heap,j;
    for(int i=n/2; i>0 ;i--)
    {
        k=i;
        v=h[k];
        heap=0;
        while(!heap && 2*k<=n)
        {
            j=2*k;
            if(j <n)
            {
                if(h[j]<h[j+1])
                    j=j+1;
            }
            if(v >=h[j])
                heap= 1;
        
        else{
            int temp=h[k];
            h[k]=h[j];
            h[j]=temp;
            k=j;
            }
        }


    }
    h[k]=v;
}

void display(int h[],int n)
{
    for(int i=1;i<=n;i++)
    {
        printf("%d ",h[i]);
    }
}

int main()
{
    int n=6;
    int h[n];
    printf("Enter the elements: ");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
        
    }
    BottomUp(h,n);
    display(h,n);
    
}