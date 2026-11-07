#include <stdio.h>
#define max 5

int queue[max];
int front = -1;
int rear = -1;

void enqueue()
{
    int value ;
    if(rear == max -1)
    {
        printf("Queue Overflow");
    }
    else
    {
        printf("Enter the value : ");
        scanf("%d",&value);

        if(front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Undnerflow");
    }
    else
    {
        printf("%d is removed ",queue[front]);
        front++;

        if(front >rear)
        {
            front = rear = -1;
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
        for(int i=front ;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
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