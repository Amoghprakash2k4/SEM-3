// SLL_full_program
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *link;
}Node;
Node* insert_front(Node *head,int element);
Node* insert_front_2(Node *head2,int element);
Node* insert_end(Node* head,int element);
void display(Node *head);
Node* createnode(int element);
Node* deleteFront(Node *head,int *ele);
Node* delete_last(Node* head,int *pele);
Node* concatinate(Node* head,int element,Node* head2);
Node* inserting_in_a_pos(Node* head,int element);
Node* adding(Node *head);
Node *max(Node *heaad);
Node *search(Node *head,int key);
Node *ins_sorted(Node *head,int ele);

int main()
{
    Node *head = NULL;
    Node *head2=NULL;
    int element;
    int choice;
    do
    {
        printf("{\n1:  InsertFront \n2:  Display \n3:  DeleteFront \n4:  insertLast\n5:  deletelast\n6:  insert front_2 \n"
        "7:  concatinate \n8:  Insert at a pos \n9:  adding the elements}\n10: Max of list\n11. searching an element \n"
        "12:  To insert an element in an sorted linked list\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nEnter the element:\n");
	            scanf("%d",&element); 
	            head = insert_front(head,element);
                break;
            case 2: if(head==NULL)
                    printf("nothing to print");
                    display(head);
                    break;
            case 3: if(head!=NULL)
                    {
                        head = deleteFront(head,&element);
                        printf("The deleted element is %d\n",element);
                    }
                    else
                    {
                        printf("List is already empty\n");
                    }
                    break;
            case 4: printf("\nEnter the element:\n");
	                scanf("%d",&element); 
	                head = insert_end(head,element);
                    break;
            case 5:if(head!=NULL)
                    {
                        head = delete_last(head,&element);
                        printf("The deleted element is %d\n",element);
                    }
                    else
                    {
                        printf("List is already empty");
                    }
                    break;
            case 6:printf("\nEnter the element:\n");
	            scanf("%d",&element); 
	            head2 = insert_front_2(head2,element);
                break;
                
            case 7: head = concatinate(head,element,head2);
                    break;
                
            case 8:printf("enter ele:  ");
                scanf("%d",&element);
                 head=inserting_in_a_pos( head,element);
            case 9: if(head==NULL)
                printf("sum=0");
                else{
                head=adding(head);}
            case 10: if(head==NULL)
                printf("nothing to print");
                else{
                    head=max(head);
                }
            case 11:if(head==NULL)
                printf("no elemnt to be fount");
                else{
                    int key;
                    printf("Enter the key: ");
                    scanf("%d",&key);
                    head=search(head,key);
                }
            case 12: if (head==NULL)
                printf("Invalid request");
                else{
                    int ele;
                    printf("Enter the element: ");
                    scanf("%d",&ele);
                    head=ins_sorted(head,ele);
                    }
        }
    } while (choice < 13);
    
}
Node* createnode(int element)
{
    Node *temp = malloc(sizeof(Node));
    temp ->data = element;
    temp->link = NULL;
    return temp;
}
// Node* concatinate(Node* head,int element)
// {
//     Node *p1=createnode(element);
//     if(head=NULL)
//     head=p1;
//     else{Node *temp=head;
//         while(temp->link!=NULL)
//         temp=temp->link;
//         temp->link=p1;

//     }
//     return head;
// }

Node* insert_front(Node *head,int element)
{
	Node *temp = createnode(element);
	//temp->data = element;
	//temp->link = NULL;
	if(head == NULL)
	head = temp;
	else    
	{
		temp->link = head;
		head = temp;
	}
	return head;
}
Node* insert_front_2(Node *head2,int element)
{
	Node *temp = createnode(element);
	//temp->data = element;
	//temp->link = NULL;
	if(head2 == NULL)
	head2 = temp;
	else    
	{
		temp->link = head2;
		head2= temp;
	}
	return head2;
}

void display(Node* head)
{
    Node* p=head;
    if(p!=NULL)
    {
        
        printf("%d ",p->data);
        display(p->link);
        
    
    }
    
}

// void display(Node *head)
// {
//     if(head == NULL)
//     {
//         printf("Empty List\n");
//     }
//     else
//     {
            // int count=0;
//         Node *p = head;
//         while(p!=NULL)
//         {
//             printf("%d, ",p->data);
//             p = p->link;
                // count++;
//         }
//         printf("\n the number of nodes is: %d  \n",count);
//     }
// }

Node* deleteFront(Node *head,int *ele)
{
    Node *p = head;
    *ele = head->data;
    head = head->link;
    free(p);
    return head;
}

Node* insert_end(Node* head,int element)
{
    Node *temp = createnode(element);
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *p = head;
        while(p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
    return head;
}

Node* concatinate(Node* head,int element,Node* head2)
{
    Node *temp = createnode(element);
    if(head == NULL)
    {
        head = head2;
    }
    else
    {
        Node *p = head;
        while(p->link != NULL)
        {
            p = p->link;
        }
        p->link = head2;
    }
    return head;
}
Node* delete_last(Node* head,int *pele)
{
    if(head->link == NULL)
    {
        *pele = head->data;
        free(head);
        head = NULL;
    }
    else
    {
        Node *p = head;
        Node *q = NULL;
        while(p->link !=NULL)
        {
            q = p;
            p = p->link;
        }
        *pele = p->data;
        q->link = NULL;
        free(p);
    }
    return head;
}
Node* inserting_in_a_pos(Node* head,int element)
{
    Node *temp = createnode(element);
    int pos;
    int count=0;
    printf("enter pos : ");
    scanf("%d",&pos);

    Node* cur;
    Node *prev;
    
    if(pos==1)
    {
       temp->link=head; 
       head=temp;
      
    }
    
    else{
        cur=head;
    while(cur->link!=NULL && count!=pos)
    {
        prev=cur;
        cur=cur->link;
        count++;
    }
    prev->link=temp;
    temp->link=cur;
     
    }
     return head;
   
}
Node* adding(Node* head)
{
    int sum=0;
    Node* p=head;
    while(p)
    {
        sum = sum + p->data;
        p = p->link;
        
    }
    printf("\nsum is : %d \n",sum);
    return head;
}
Node *max(Node *head)
{
    Node* p=head;
    int m=-32768;
    while(p)
    {
        if(m<p->data)
        m=p->data;
        p=p->link;
    }
    printf("the largest elemnet is : %d \n",m);
    return head;
}
Node* search(Node* head,int key) ///     not working 
{
    Node* p=head;
    int count=0;
    while(p->data==key)
    {
        p=p->link;
        count++;

    }
    printf("%d",count);
    return head;
}
Node *ins_sorted(Node *head,int ele)
{
    Node *p=head;
    Node *q;
    while(p && p->data < ele)
    {
        q=p;
        p=p->link;

    }
    Node *temp=createnode(ele);
    temp->link=p;
    q->link=temp;
    return head;
}