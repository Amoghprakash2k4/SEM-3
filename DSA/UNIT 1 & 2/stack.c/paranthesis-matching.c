#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 20
int empty(int top)
{
    return top == -1;
}
int  push(int *stk,int *top,int ele)
 {
    stk[++(*top)]=ele;
 }
char pop(int *stk, int *top) 
{
        return stk[(*top)--]; 
}

int matching(char* input, char* output)
{
    int ch,x;
    int stk[n];
    int i=0;
    int top = -1;
    while(input[i]!= '\0')
        {
            ch= input[i];
            switch(ch)
            {
                case '(': 
                case '{':
                case '[':
                    push(stk,&top,ch);
                    break;
                case ')': if(!empty(top))
                        {
                            x=pop(stk,&top);
                            if(x=='(')
                                break;
                            else    
                                return 0;
                        }
                        else
                            return 0;
                case '}': if(!empty(top))
                            {
                                x=pop(stk,&top);
                                if(x=='{')
                                    break;
                                else
                                    return 0;
                            }
                            else
                                return 0;
                 case ']': if(!empty(top))
                            {
                                x=pop(stk,&top);
                                if(x=='[')
                                    break;
                                else
                                    return 0;
                            }
                            else
                                return 0;


            }
            i++;
        }
        if(empty(top))
            return 1;
        else    
            return 0;
}

int main()
{
    int ele;
    char input[n];
    char output[n];
    printf("Enter the paranthesis: ");
    scanf("%s",input);
    int result= matching(input,output);
    if(result == 1)
        printf("Paranthesis are matching");
    else
        printf("Paranthesis mismatch"); 
}