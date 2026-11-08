#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ;
    struct node *next;
};

struct node *head = NULL;
void insertbegin()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&newnode -> data);
    newnode -> next = head;
    head = newnode;
}
void insertend()
{
    struct node *newnode,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&newnode -> data);
    newnode -> next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
    
}
void insertposition()
{
    int pos;
    struct node *newnode,*temp;
    printf("Enter the position : ");
    scanf("%d",&pos);

    if(pos<1)
    {
        printf("Invalid position");
    }

    if(pos == 1)
    {
        insertbegin();
        return;
    }
     temp = head;

     for(int i = 1 ; i<pos-1 && temp != NULL; i++)
     {
        temp = temp -> next;
     }
     if(temp == NULL)
     {
        printf("Invalid position");
     }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data : ");
    scanf("%d",&newnode -> data);

    newnode -> next = temp -> next;
    temp -> next = newnode;

}
void deletebegin()
{
    struct node *temp ;

    if(head == NULL)
    {
        printf("List is empty");
    }
    else
    {
    temp = head;
    head = head -> next;
    free(temp);
    }
}

void deleteend()
{
    struct node *temp,*prev;

    if(head == NULL)
    {
        printf("List is empty");
    }
    else if(head ->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
    temp = head;

    while(temp -> next != NULL)
    {
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = NULL;
    free(temp);
}
}

void deleteposition()
{
    int pos;
    struct node *prev,*temp;
    printf("Enter the position : ");
    scanf("%d",&pos);

    if(pos<1 || head == NULL)
    {
        printf("Invalid position");
    }

     if(pos == 1)
    {
        deletebegin();
        return;
    }
     temp = head;

     for(int i = 1 ; i<pos && temp != NULL; i++)
     {
        prev = temp;
        temp = temp -> next;
     }
      if(temp == NULL)
     {
        printf("Invalid position");
     }
    prev -> next = temp -> next;
    free(temp);


}

void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty");
    }
    else{
    temp = head;

    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp -> next;
    }
    printf("NULL\n");
}
   
}

int main()
{
    int choice;
    while(1)
    {
        printf("1.insertbegin\n");
        printf("2.insertend\n");
        printf("3.insertpostion\n");
        printf("4.deletebegin\n");
        printf("5.deleteend\n");
        printf("6.deletepostion\n");
        printf("7.display\n");
        printf("8.exit\n");
    
    


        printf("Enter a choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:insertbegin();break;
            case 2:insertend();break;
            case 3:insertposition();break;
            case 4:deletebegin();break;
            case 5:deleteend();break;
            case 6:deleteposition();break;
            case 7:display();break;
            case 8:exit(0);break;
        }
    }
}