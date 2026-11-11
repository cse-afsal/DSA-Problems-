#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue[max];
int front = -1 ;
int rear = -1;

void enqueue()
{
    int value;
    if((rear+1)%max == front)
    {
        printf("Queue is full");
    }
    else
    {
        printf("Enter the value : ");
        scanf("%d",&value);

        if(front == -1)
        {
            front =0;
            rear =0;
        }
        else
        {
            rear = (rear+1)%max;
        }
    }
    queue[rear] = value;
    printf("%d is enqueued",value);
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front +1 )%max;
        }
    }
}

void display()
{
    if(front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        int i = front;

        while(1)
        {
            printf("%d ",queue[i]);

            if(i == rear)
             break;
             
            i=(i+1)%max;

            
           
        }
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n 1.enqueue\n");
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