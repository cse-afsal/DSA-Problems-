#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Stack is empty");
    }
    printf("Enter the number : ");
    scanf("%d",&newnode -> data);
    newnode -> next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("Stack is empty");
    }
    temp = top;
    top = top -> next;
    free(temp);
}
void peek()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("Stack is empty");
    }
    printf("%d is top",top -> data);
}   

void display()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("Stack is empty");
    }
    temp = top;
    while(temp != NULL)
    {
        printf("%d ",temp -> data);
        temp = temp -> next;
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