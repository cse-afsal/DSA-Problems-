#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
    char page[100];
    struct node *prev;
    struct node *next;
};

struct node *current = NULL;

void visit(char name[])
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    strcpy(newnode -> page , name);

    newnode -> next = NULL;
    newnode -> prev = current;

    if(current != NULL)
    {
        current -> next = newnode;
    }
    current = newnode;

    printf("%s is visited \n", current -> page);

}

void back()
{
    if(current == NULL || current -> prev == NULL)
    {
        printf("There is no previous page");
    }
    else
    {
        current = current -> prev;
        printf("%s \n",current -> page);
    }
}

void forward()
{
    if(current == NULL || current -> next == NULL)
    {
        printf("There is no next page \n");
    }
    else
    {
        current = current -> next;
        printf("%s \n",current -> page);
    }
}

void display()
{
    struct node *temp = current;

    if(temp == NULL)
    {
        printf("There is no page is visited \n");
    }
    while(temp -> prev != NULL)
    {
        temp = temp -> prev;
    }
    while(temp != NULL)
    {
        printf("%s ->",temp -> page);
        temp = temp -> next;
    }
}
int main()
{
    char name[100];
    int choice;

     while(1)
    { 
    printf("\nWEB Navigation \n");
    printf("1.visit webpage \n");
    printf("2.previous page \n");
    printf("3.next page \n");
    printf("4.display \n");
    printf("5.exit \n");

    printf("\nEnter the choice : ");
    scanf("%d",&choice);

   

    switch(choice)
    {
        case 1: 
         printf("\nEnter the page name to visit : ");
         scanf("%s",name);
         visit(name);break;
        case 2:
         back();break;
        case 3:
         forward();break;
        case 4:
         display();break;
        case 5:
         exit(0);break;
    }
}

}