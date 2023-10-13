//Creating a menu based linked list for the user.
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node* createNode(int data){
    Node* new=(Node*)malloc(sizeof(Node));
    new->data=data;
    new->next=NULL;
    return new;
}

Node* insertfront(Node* head,Node* new){
    new->next=head;
    return new;
}

Node* deletefront(Node* head){
    if(head==NULL){
        printf("Empty List\n");
        return head;
    }
    Node *temp=(Node*)malloc(sizeof(Node));
    temp=head;
    head=head->next;
    free(temp);
    return head;
}


void display(Node* head){
    if(head==NULL){
        printf("Empty List!!\n");
        return;
    }
    printf("{");
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\b}\n");
    return;
}

int main(){
    Node* head=NULL;
    Node *tail=NULL;
    int ch,ele,pos=0;
    do{
        printf("1. InsertFront\n2. DeleteFront\n 3. Display\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element you want to insert: ");
                scanf("%d",&ele);
                head=insertfront(head,createNode(ele));
                break;
            
            case 2:
                printf("Deleting...\n");
                head=deletefront(head);
                break;
            
             case 3: printf("The elements are: \n");
                display(head);
                break;
            //     printf("Enter the element you want to insert: ");
            //     scanf("%d",&ele);
            //     head=insertlast(head,createNode(ele));
            //     break;

            // case 4:
            //     printf("Deleting...\n");
            //     head=deletelast(head);
            //     break;

            // case 5:
            //     printf("Enter the element and position: ");
            //     scanf("%d %d",&ele,&pos);
            //     head=insertmiddle(head,createNode(ele),pos);
            //     break;

            // case 6:
            //     printf("Enter the position of element you want to delete: ");
            //     scanf("%d",&pos);
            //     printf("Deleting....\n");
            //     head=deletemiddle(head,pos);
            //     break;

            // case 7:
            //    

            case 0:
                printf("Exiting...");
                break;
            
            default:
                printf("Invalid choice. Enter again.\n");
                break;
        }
    }while(ch);
    return 0;
}