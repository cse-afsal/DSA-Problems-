#include <stdio.h>

int partition(int a[],int low , int high)
{
    int temp;
    int pivot = a[high];
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    return i+1;

}
void quicksort(int a[],int low,int high)
{
    int p;
    if(low<high)
    {
        p=partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
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
        
        quicksort(a,0,n-1);

        printf("Sorted array ");
        for(int i=0;i<n;i++)
        {
            printf(" %d ",a[i]);
        }

    }