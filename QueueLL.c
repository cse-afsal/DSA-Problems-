#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element : ");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL;

    if(front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear -> next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    struct node *temp;
    
    if(front == NULL)
    {
        printf("Queue is empty");
    }
    else if(front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        temp = front ;
        front = front -> next;
        free(temp);
    }
}

void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        temp = front;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp -> next;
        }
    }

}

int main()
{
    int choice;
    while(1)
    {
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("4.exit\n");
    


        printf("Enter a choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:enqueue();break;
            case 2:dequeue();break;
            case 3:display();break;
            case 4:exit(0);break;
        }
    }
}