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

    printf("%s is visited ", current -> page);

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
        printf("%s ",current -> page);
    }
}

void forward()
{
    if(current == NULL || current -> next == NULL)
    {
        printf("There is no next page");
    }
    else
    {
        current = current -> next;
        printf("%s",current -> page);
    }
}

void display()
{
    struct node *temp = current;

    if(current == NULL)
    {
        printf("There is no page is visited");
    }
    while(temp -> prev != NULL)
    {
        temp = temp -> prev;
    }
    while(temp != NULL)
    {
        printf("%s ->",current -> page);
        temp = temp -> next;
    }
}
int main()
{
    char name[100];
    int choice;

    printf("WEB Navigation");
    printf("1.visit webpage");
    printf("2.previous page");
    printf("3.next page");
    printf("4.exti");

    printf("Enter the choice : ");
    scanf("%d",choice);

    switch(choice)
    {
        case 1: 
         printf("Enter the page name to visit : ");
         scanf("%s",name);
         
    }


}