#include <stdio.h>
void search(int a[], int key , int n)
{
    int found = 0;
    for (int i = 0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("%d is found at %d",key,i+1);
            found = 1;
            break;
        }  
    }
    if(found == 0)
    {
        printf("Element not found");
    }
}
int main()
{
    int a[100],n,key = 0;

    printf("Enter the number of elements : ");
    scanf("%d",&n);

    printf("Enter the elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to find : ");
    scanf("%d",&key);

    search(a,key,n);

}