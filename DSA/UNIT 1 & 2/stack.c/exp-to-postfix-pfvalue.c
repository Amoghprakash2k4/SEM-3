#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define n 20

// From here the code is to convert expression to postfix

int operand(char symb) {   //to check if the encounterd element in operator oparand
    if (symb == '+' || symb == '-' || symb == '*' || symb == '/')
        return 0;
    else
        return 1;
}

//For evaluvating the precedence of operator
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

//To check if the stack is empty
int empty(int top1) {
    return top1 == -1;
}

// to push into postfix array
void push1(int *stk1, int *top1, int ele) {
    stk1[++(*top1)] = ele;
}

// to popout of postfix array
int pop1(int *stk1, int *top1) {
    if (!empty(*top1)) {
        return stk1[(*top1)--];
    } else {
        return -1; // Stack is empty
    }
}

// To convert infix to postfix
char* inftopos(char *infix, char *postfix) {
    char stack[20];
    int top = -1;
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (operand(current)) {
            postfix[j++] = current;
        } 
        else if (!operand(current))
         {
            while (top >= 0 && precedence(stack[top]) >= precedence(current)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = current;
        } 
        else if (current == '(') {
            stack[++top] = current;
        } else if (current == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') {
                top--; // Pop the '('
            }
        }
    }

    while (top >= 0) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
    return postfix;
}

// From here the code is to  evaluvate the postfix 

void push(int *stk,int *top,int ele )
{
    stk[++(*top)]=ele;
} 

int pop(int *stk, int *top)
{    
    return stk[(*top)--];
}

int val(int opd1,int opd2,char symb)// to perform operation
{
    switch(symb)
    {
        case '+': return (opd1+opd2);
        case '-': return(opd2-opd1);
        case '*': return (opd1 * opd2);
         case '/': return(opd2/opd1); 
    }
}




int isnum(int ch)  //to check if it in operator or operand
{
    if (ch>=0 && ch<=9)
    return 1;
    else 
    return 0;
    
}

int postfix_exp(char* minires)   //to evaluvate postfix exp. 
{
    int stk[n];
    int top=-1;
    int i=0,opd1,opd2;
     int res;
    while(minires[i]!= '\0')
    {
        char symb=minires[i];
        if(isnum(symb - '0'))
        {
            push(stk,&top,symb-'0');
            i++;
        }
        else
        {
             opd1=pop(stk,&top);
             opd2=pop(stk,&top);
             res= val(opd1,opd2,symb);
            push(stk,&top,res);
          i++;
         }
    
    }   
return pop(stk,&top);  //pop cause the  final output after evaluvation is pushed back into stack,so to dispaly it
}

int main()
{
    char input[n];
    char postfix[n];
    printf("Enter the input: ");
    scanf("%s", input);
    int minires=inftopos(input, postfix);

    printf("The postfix expression is: %s\n", postfix);
    int result= postfix_exp(postfix);
    printf("The evlaluvated value of postfix expression is :  %d", result);
}

// To check if it is working : input=2+3*4:  postfix exp= 234*+:  evaluvated ans= 14;