#include <stdio.h>
struct p
{
    int exp;
    int coff;
};
int main()
{
    struct p p1[20],p2[20],p3[40];
    int n1 , n2 , k = 0;

    printf ("Enter the number of terms in first polynomial : ");
    scanf("%d",&n1);

    printf("Enter the exponent and coefficent : ");
    for(int i=0;i<n1;i++)
    {
      scanf("%d %d",&p1[i].exp , &p1[i].coff);
    }

    printf("Enter the number of terms in second polynomial : ");
    scanf("%d",&n2);

    printf("Enter the exponent and coefficent : ");
    for(int i=0;i<n2;i++)
    {
      scanf("%d %d",&p2[i].exp , &p2[i].coff);
    }
    int i = 0 , j = 0 ;

    while (i<n1 && j<n2)
    {
        if(p1[i].exp == p2[j].exp)
        {
            p3[k].coff = p1[i].coff + p2[i].coff;
            p3[k].exp = p1[i].exp;

            i++;
            j++;
            k++;
        }
        else if(p1[i].exp > p2[i].exp)
        {
            p3[k] = p1[i];
            i++;
            k++;
        }
        else
        {
            p3[k] = p2[j];
            j++;
            k++;
        }

    }

    while (i < n1)
    {
        p3[k] = p1[i];
        i++;
        k++;
    }
    while (i < n2)
    {
        p3[k] = p2[j];
        j++;
        k++;
    }
printf("Resultant polynomial");
for(int i=0;i<k;i++)
{
    printf("%dX^%d ",p3[i].coff,p3[i].exp);

    if(i<k-1)
    printf("+");
}

}