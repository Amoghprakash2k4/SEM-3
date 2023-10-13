#include<stdio.h>
#define MAX 5
void enqueue(int *q, int *r, int ele)
{
	if(*r==MAX-1)
		printf("queue is full\n");
	else
	{
		int j=*r;
		while(j>=0 && ele< q[j])
		{
			q[j+1]=q[j];
			j--;
		}
		q[j+1]=ele;
		*r=*r+1;
	}
}
void display(int *q, int f, int r)
{
	if(f>r)
		printf("queue is empty\n");
	else
	{
		for(int i=f;i<=r;i++)
			printf("%d\t",q[i]);
	}
}
int dequeue(int *q, int *f, int r)
{
	if(*f>r)
		return(9999);
	else
	{
		int x;
		x=q[*f];
		*f=*f+1;
		return(x)   ;
	}
}	
	
int main()
{
	int f=0,r=-1;
	int q[MAX];
	int ch,ele,x;
	while(1)
	{
		printf("1.Enqueue\n 2.Dequeue\n 3.display\n");
		printf("Enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the Element\n");
			scanf("%d",&ele);
			enqueue(q,&r,ele);
			break;
			case 2:x=dequeue(q,&f,r);
			if(x==9999)
				printf("underflow condition\n");
			else{
				printf("deleted element is %d\n",x);
			}
				break;
			case 3:display(q,f,r);
			break;
		}
	}
	return(0);
}