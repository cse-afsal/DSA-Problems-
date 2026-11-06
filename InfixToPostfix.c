#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top]=x;
}

char pop()
{
    return stack[top--];
}

int precedence(char x)
{
    if(x=='^')
     return 3;
    else if(x=='*' || x=='/')
     return 2;
    else if(x=='+' || x=='-')
     return 1;
    else
     return 0;
}

void infixToPostfix(char infix[])
{
    char postfix[100];
    char x;
    int i,j=0;

    for(int i=0;infix[i] != '\0';i++)
    {
       if(isalnum(infix[i]))
       {
        postfix[j++]=infix[i];
       }
       else if(infix[i]=='(')
       {
        push(infix[i]);
       }
       else if(infix[i]==')')
       {
        while(top!=-1 && stack[top]!='(')
        {
            postfix[j++]=pop();     
           
        }
         if(top!=-1)
         pop();
        }
       else
       {
        while(top!=-1 && stack[top]!='(' && (precedence(stack[top]) > precedence(infix[i])) ||
             (precedence(stack[top]) == precedence(infix[i]) && infix[i] != '^'))
        {
            postfix[j++]=pop();
        }
        push(infix[i]);
       }
    } 
    
    while(top!=-1)
    {
        postfix[j++] = pop();
    }
    postfix[j]='\0';
    printf("Postfix Expression : %s ",postfix);

}

int main()
{
    char infix[100];
    printf("Enter infix expression : ");
    scanf("%99s",infix);

    infixToPostfix(infix);
    return 0;
}