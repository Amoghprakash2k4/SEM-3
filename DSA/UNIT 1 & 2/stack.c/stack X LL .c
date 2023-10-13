#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}Node;

Node* createNode(int ele){
    Node* new=(Node*)malloc(sizeof(Node));
    new->data=ele;
    new->next=NULL;
    return new;
}

Node* pushele(Node* top,Node* new){
    if(top==NULL){
        return new;
    }
    new->next=top;
    return new;
}

Node* pop(Node* top){
    if(top==NULL){
        printf("Empty Stack. Cannot Delete!!\n");
        return NULL;
    }
    Node* temp=top;
    top=top->next;
    free(temp);
    return top;
}

void display(Node* top){
    if(top==NULL){
        printf("Empty Stack!!!\n");
        return;
    }
    Node* temp=top;
    printf("{");
    while(temp!=NULL){
        printf("%d, ",temp->data);
        temp=temp->next;
    }
    printf("\b\b}\n");
    
}

int main(){
    Node* top=NULL;
    int ele,choice,count=0;
    do{
        printf("  MENU\n1. Push\n2. Pop\n3. Peek\n4. Display\n\n  Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element you want to insert: ");
                scanf("%d",&ele);
                top=pushele(top,createNode(ele));
                count++;
                break;
            case 2:
                printf("Deleting...\n");
                top=pop(top);
                count--;
                break;
            case 3:
                printf("The topmost element of stack is %d.\n",top->data);
                break;
            case 4:
                display(top);
                break;
            case 0:
                printf("Exiting...\n");
            default:
                printf("Invalid choice. Enter Again\n");
                break;
        }
    }while(choice);
    return 0;
}