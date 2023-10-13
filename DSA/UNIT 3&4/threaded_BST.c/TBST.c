#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *leftlink;
    struct Node *rightlink;
    int rthread;
}Node;

typedef struct tree
{
    Node *root;
}tree; 

void init(tree *p)
{
    p->root=NULL;
    return;
}

Node* createNode(int ele){
    Node *temp =(Node*)malloc(sizeof(Node));
    temp->data= ele;
    temp->leftlink=NULL;
    temp->rightlink=NULL;
    return temp;     
}


void insertnode(tree *p,Node *temp)
{
  
    if(p->root==NULL)
    {   
        p->root=temp;
        return;
    }
    
    Node *curr=p->root;
    Node *prev=NULL;
    while(curr!=NULL)
    {
        prev=curr;
        if(temp->data==curr->data)
        {return;
        }
        else if(temp->data< curr->data) 
        {
            curr=curr->leftlink;
             setLeft(curr,temp->data);
        }
        else{
            curr= curr->rightlink;
            setRight()
        }
    }
    if(temp->data > prev->data)
        prev->rightlink=temp;
    else{
        prev->leftlink= temp;
    }
}

Node* del(Node *r,int key)
{
    Node *temp,*p;
    if(r==NULL)
        return r;
    if(key < r->data)
       r->leftlink=del(r->leftlink,key);
    else if(key > r->data)
       r->rightlink=del(r->rightlink,key);
    else{
        if(r->leftlink==NULL)
        {
            temp=r->rightlink;
            free(r);
            return temp;
        }
        else if(r->rightlink==NULL)
        {
            temp=r->leftlink;
            free(r);
            return temp;
        }
        else{
            p=r->rightlink;
            while(p->leftlink != NULL)
                p=p->leftlink;
             r->data = p->data;
            r->rightlink=del(r->rightlink,p->data);

        }
    }
    return r;
}
void deletenode(tree *n,int ele)
{
    n->root=del(n->root,ele);
}

void display(Node *root)
{
    if(root!=NULL)
    {
        display(root->leftlink);
        printf("%d,  ",root->data);
        display(root->rightlink);    
    }
}

void search(Node *root, int key)
{
    Node *cur = root;
    while (cur != NULL)
    {
        if (key == cur->data)
        {
            printf("Element found\n");
            return; // Exit the function when the element is found
        }
        else if (key > cur->data)
            cur = cur->rightlink;
        else
            cur = cur->leftlink;
    }
    printf("Element not found\n"); // Print this after the while loop
}

void setLeft(Node* q,int ele)
{
    q->leftlink=temp;
    temp->rightlink=q;
}
void setRight(Node*q ,int ele)
{

    temp->rightlink=q->rightlink;
    q->right= temp;
    q->rthread=0;
    
}


void inorderTraversal(Node* root) {
if (root != NULL) {
inorderTraversal(root->leftlink);
printf("%d ", root->data);
inorderTraversal(root->rightlink);
}
}


void preorderTraversal(Node* root) {
if (root != NULL) {
printf("%d ", root->data);
preorderTraversal(root->leftlink);
preorderTraversal(root->rightlink);
}
}

void postorderTraversal(Node* root) {
if (root != NULL) {
postorderTraversal(root->leftlink);
postorderTraversal(root->rightlink);
printf("%d ", root->data);
}
}




int main()
{
    int ch,ele,key; 
    tree var;
    init(&var); 

   
    do{ printf("\n1. Insert  \n2. Deletenode \n3. Display \n4. Search \n{5. Inorder \n6. Preorder \n7. Postorder} some issues \n----------------- \n ");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        printf("\n");
        switch (ch)
        {
        case 1: printf("Enter the value: ");
                scanf("%d",&ele);
                printf("\n");
                insertnode(&var,createNode(ele));
                break;

        case 2: printf("Enter the element yo want to delete: ");
                scanf("%d",&key);
                deletenode(&var,key);
                printf("\nElement deleted\n")   ;
                break;
         case 3: 
                display(var.root); //inorder
                break;

        case 4:printf("Enter the element to be found:");
                scanf("%d",&key);
                printf("\n");
                search(var.root, key);
            break;
        case 5:inorderTraversal(var.root);
        case 6:preorderTraversal(var.root);
        case 7:postorderTraversal(var.root);
        }
    }while(ch<8);
}