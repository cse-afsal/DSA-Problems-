#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff,exp;
    struct node *next;
};

struct node *create(int c,int e)
{
    struct node *newnode , *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    
    newnode -> coeff = c;
    newnode -> exp = e;
    newnode -> next = NULL;

    return newnode;
}

struct node *insert(struct node *head,int c,int e)
{
    struct node *temp , *newnode;
    newnode = create(c,e);

    if(head == NULL)
    {
        return newnode;
    }

    temp = head;
    while (temp != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;

    return head;
}

struct node *add(struct node *p1,struct node *p2)
{
    struct node *result = NULL;

    while(p1 != NULL && p2 != NULL)
    {
        if(p1 -> exp == p2 -> exp)
        {
            result = insert(result,p1->coeff + p2 -> coeff,p1->exp);
        }
    }
}