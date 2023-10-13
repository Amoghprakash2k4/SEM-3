#include<stdio.h>
#include<stdlib.h>

int isOperand(char ele) {
    return (ele >= '0' && ele <= '9');
}

typedef struct Node {
    int data;
    struct Node *leftlink;
    struct Node *rightlink;
} Node;

Node* CreateNode(int ele) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = ele;
    temp->leftlink = NULL;
    temp->rightlink = NULL;
    return temp;
}

Node* create_expression(Node* stk[50]) {
    char postfix[50];
    int i = 0, k = -1; // Initialize k to -1
    char symb;
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    while (postfix[i] != '\0') {
        symb = postfix[i];
        Node* temp = CreateNode(symb);
        if (isOperand(symb))
            stk[++k] = temp;
        else {
            temp->rightlink = stk[k--];
            temp->leftlink = stk[k--];
            stk[++k] = temp;
        }
        i++;
    }
    return stk[k];
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->leftlink);
        printf("%d ", root->data);
        inorderTraversal(root->rightlink);
    }
}

float eval(Node* root) {
    float val;
    if (root->leftlink == NULL && root->rightlink == NULL) {
        printf("Enter the value for %d: ", root->data);
        scanf("%f", &val);
        return val;
    }
    int lval = eval(root->leftlink);
    int rval = eval(root->rightlink);
    if (root->data == '+')
        return lval + rval;
    if (root->data == '-')
        return lval - rval;
    if (root->data == '*')
        return lval * rval;
    else {
        if (rval == 0) {
            printf("Error: Division by zero\n");
            exit(1);
        }
        return lval / rval;
    }
}

int main() {
    int ch, ele, key;
    float res;
    Node* root;
    Node* stk[50];
    root = create_expression(stk);
    inorderTraversal(root);
    res = eval(root);
    printf("The result is : %f\n", res); // Use %f for printing a float
    return 0;
}
