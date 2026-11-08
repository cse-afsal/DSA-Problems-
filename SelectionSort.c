#include <stdio.h>

void sort(int a[],int n)
{
    int min,temp;

    for(int i=0;i<n -1;i++)
    {
        min = i;
        
        for(int j =i+1;j<n;j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i]=a[min];
        a[min]=temp;
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
        
        sort(a,n);

        printf("Sorted array ");
        for(int i=0;i<n;i++)
        {
            printf(" %d ",a[i]);
        }

    }