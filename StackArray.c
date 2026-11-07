#include <stdio.h>
#define max 5

int stack[max];
int top = -1;

void push()
{
    int value;

    if(top == max -1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the number : ");
        scanf("%d",&value);
        stack[++top] = value;
        printf("Element is inserted\n");
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d is poped\n ",stack[top]);
        top--;
    }
}

void peek()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Stack top is %d\n",stack[top]);
    }
}

void display()
{
    if(top == -1)
    {
        printf("Stack is empty \n");
    }
    else
    {
        for(int i=top ; i>= 0 ; i--)
        {
            printf("%d ",stack[i]);
        }
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.dispaly\n");
        printf("5.exit\n");


        printf("Enter a choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:peek();break;
            case 4:display();break;
            case 5:exit(0);break;
        }
    }
}