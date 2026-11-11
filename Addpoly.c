#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int coeff,exp;
    struct node *next;
};

struct node *create(int c , int e)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode -> coeff = c;
    newnode -> exp = e;
    newnode -> next = NULL;

    return newnode;
}

struct node *insert(struct node *head,int c, int e)
{
    struct node *newnode,*temp;

    newnode = create(c,e);

    if(head == NULL)
    {
        return newnode;
    }
    temp = head;

    while(temp -> next != NULL)
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
        if(p1->exp == p2->exp)
        {
            result = insert(result,p1->coeff + p2-> coeff,p1->exp);
            p1 = p1-> next;
            p2 = p2-> next;
        }
        else if(p1 ->exp > p2-> exp)
        {
            result = insert(result,p1->coeff,p1->exp);
            p1=p1->next;
        }
        else
        {
            result = insert(result,p2->coeff,p2->exp);
            p2=p2->next;
        }
    }
    while(p1 != NULL)
    {
        result = insert(result,p1->coeff,p1->exp);
        p1=p1->next;
    }
    while(p2!=NULL)
    {
        result = insert(result,p2->coeff,p2->exp);
        p2=p2->next;
    }
    return result;

}

void display(struct node *head)
{
    while(head != NULL)
    {
        printf("%d X ^ %d",head -> coeff,head -> exp);

        if(head -> next != NULL)
        {
            printf(" + ");
        }
        head = head -> next;
    }
    printf("\n");
}

int main()
{
    struct node *p1 = NULL,*p2 = NULL,*sum = NULL;
    int c , e,n;

    printf("Enter the number of terms in first polynomial : ");
    scanf("%d",&n);
    
    printf("Enter the coeff and exponent : ");
    for(int i=0;i<n;i++)
    {
       scanf("%d %d",&c,&e);
       p1 = insert(p1,c,e);
    }

    printf("Enter the number of terms in second polynomial : ");
    scanf("%d",&n);
    
    printf("Enter the coeff and exponent : ");
    for(int i=0;i<n;i++)
    {
       scanf("%d %d",&c,&e);
       p2 = insert(p2,c,e);
    }

    printf("first  polynomial : ");
    display(p1);

     printf("second  polynomial : ");
    display(p2);

    sum = add(p1,p2);

     printf("sum polynomial : ");
    display(sum);
    
    
}
