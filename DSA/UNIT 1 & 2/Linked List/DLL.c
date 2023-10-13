p#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    struct Node *link1;
    struct Node *link2;
    int data;
}Node;
struct list
{
    Node *head;
};
typedef struct list DLIST;

void init(DLIST *ptr)
{
    ptr->head=NULL;
}

void insert_front(Node *head,int element);
void display(Node *head);
Node*createNode(int element,Node* head);
void deleteFront(Node *head);


int main()
{
    Node *head = NULL;
    Node *head2=NULL;
    int element;
    int choice;
    do
    {
        printf("{\n1:  InsertFront \n2:  Display \n3:  DeleteFront \n5:Delete Last\n");
        // 4:  insertLast\n5:  deletelast\n6:  insert front_2 \n7:  concatinate \n8:  Insert at a pos \n}\n ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nEnter the element:\n");
	            scanf("%d",&element); 
	            insert_front(head,element);
                break;
            case 2: display(head);
                    break;
            case 3: if(head!=NULL)
                    {
                        deleteFront(head);
                        printf("The deleted element is %d\n",element);
                    }
                    else
                    {
                        printf("List is already empty\n");
                    }
                    break;
            // case 4: printf("\nEnter the element:\n");
	        //         scanf("%d",&element); 
	        //         head = insert_end(head,element);
            //         break;
            case 5:if(head!=NULL)
                    {
                        delete_last(head,&element);
                       
                    }
                    else
                    {
                        printf("List is empty");
                    }
                    break;
        }
    }while(choice< 8);
} 

Node* createNode(int element,Node* head)
{
    Node *temp=malloc(sizeof(Node));
    temp->data=element;
    temp->link1=NULL;
    temp->link2=NULL;
    return temp;
}
void insert_front(Node* head, int element){
    Node *temp=createNode(element,head);
    if(head==NULL)
    {
        head=temp;
    }
    else{
        temp->link2=head;
        head->link1=temp;
        head=temp;
    }
    return;
}

void display(Node *head)
{
    if(head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        Node *p = head;
        while(p!=NULL)
        {
             
            printf("%d, ",p->data);
            p = p->link2;

        }
        printf("\n");
    }
    return;
}
void deleteFront(Node *head)
{
    if(head->link2==NULL)
    {
        free(head);
        head=NULL;

    }
   else{
    Node* p=head;
    head=head->link2;
    free(p);
   }
  return;
}
/*
1. if it is already NULL then retun empty
2. if only one node is there freee the node and make head NULL
3. if more than one then use one  temp pointer and traverse till last makind prev node NULL and free the last node 
*/
void delete_last(Node *head,int element)
{
     Node* temp=head;
    
    if(temp==NULL)
    {
        printf("lready empty");
    }
    else if(temp->link2==NULL)
    {
       
        free(temp);
        head=NULL;
    }
    else   {
        Node *temp=NULL;
        while(temp->link2!=NULL)
        {
            temp=temp->link2;

        }
        temp->link1=NULL;
        free(temp);
        
    }
    return;

    
}

/*
1. insert at first position means use insert front function
2. if insert at last position means use insert last 
3. if insert in middle means after taversing to specified node point to previous and next previous node so that youll have grip over both node 
    use count to check if next is reached to desired position , then make temp node l2 point to next , and l1 of temp point to l2 of prev node at last free the temp pointer
4. if they give position > count it should return invalid
*/