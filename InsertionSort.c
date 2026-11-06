#include <stdio.h>
void insertionsort(int a[],int n)
{
    int key;
    for(int i=1;i<n;i++)
    {
        key = a[i];
        int j=i-1;

        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;

    }
}

int main()
    {
        int n,a[100];
        printf("Enter the no of elements : ");
        scanf("%d",&n);
        printf("Enter the elements : ");
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        insertionsort(a,n);
        printf("Sorted array ");
        for(int i=0;i<n;i++)
        {
            printf(" %d ",a[i]);
        }

    }