#include <stdio.h>
#include <stdlib.h>
#define max 5

int dequeue[max];
int front = -1;
int rear = -1;

void insertfront()
{
    int value;
    if((front == 0) && (rear == max -1) || (front == rear +1))
    {
        printf("Dequeue is empty \n");
    }
    printf("Enter the number : ");
    scanf("%d",&value);
    if(front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = max -1;
    }
    else
    {
        front --;
    }

    dequeue[front]=value;
}

void insertrear()
{
    int value;
    if((front == 0)&& (rear == max-1) || (front == rear+ 1))
    {
        printf("Dequeue is empty");
    }
    printf("Enter the nubmer : ");
    scanf("%d",&value);
    if(front ==-1)
    {
        front = rear = 0;
    }
    else if(rear == max -1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    dequeue[rear]=value;
}

void deletefront()
{
    
    if(front == -1)
    {
        printf("Dequeue is empty");
    }
    
    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == max -1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    
}

void deleterear()
{
    
    if(front == -1)
    {
        printf("Dequeue is empty");
    }
    
    if(front == rear)
    {
        front = rear = -1;
    }
    else if(rear == 0)
    {
        rear = max - 1;
    }
    else
    {
        rear--;
    }
    
}
void display()
{
    if(front == -1)
    {
        printf("Dequeue is empty");
    }
    int i = front;
    while(1)
    {
        printf("%d ",dequeue[i]);

        if(i == rear)
        break;

        i=(i+1)%max;
    }
    printf("\n");
}

int main()
{
    int choice;
    while(1)
    {
        printf("1.insertfront\n");
        printf("2.insertrear\n");
        printf("3.deletefront\n");
        printf("4.deleterear\n");
        printf("5.display\n");
        printf("6.exit\n");
    


        printf("Enter a choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:insertfront();break;
            case 2:insertrear();break;
            case 3:deletefront();break;
            case 4:deleterear();break;
            case 5:display();break;
            case 6:exit(0);break;
        }
    }
}