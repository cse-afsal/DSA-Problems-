#include <stdio.h>

int search(int a[],int n,int key)
{
    int i,j;
    int low = 0, high = n - 1, mid = 0;

    while(low<=high)
    {
        mid = (low + high)/2;

        if(a[mid] == key)
        {
            return mid;
        }
        else if(key<a[mid])
        {
           high = mid - 1;
        }
        else if(key>a[mid])
        {
            low = mid + 1;
        }
        else
        {
            return -1;
        }
    }
    
}

int main()
{
    int a[100],n,result,key;

    printf("Enter the number of elements : ");
    scanf("%d",&n);

    printf("Enter the elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to find");
    scanf("%d",&key);

    result = search(a,n,key);
   
    if(result == -1)
    {
        printf("Element not found ");
    }
    else
    {
        printf("%d is found in %d ",key,result+1);
    }

}