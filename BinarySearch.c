#include <stdio.h>

int search(int a[],int key , int n)
{
    int mid,low=0,high=n-1;
    while(low<=high)
    {
        mid = (low + high)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]<key)
        {
            low = mid + 1;
        }
        else 
        {
           high = mid -1;
        }
        
    }
    return -1;
   
}
int main()
{
    int a[100],n,key = 0,result;

    printf("Enter the number of elements : ");
    scanf("%d",&n);

    printf("Enter the elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to find : ");
    scanf("%d",&key);

    result = search(a,key,n);

    if (result == -1)
    {
        printf("Element Not found");
    }
    else
    {
        printf("%d is found at %d",key,result+1);
    }

}