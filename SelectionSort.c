#include <stdio.h>

void sort(int a[],int n)
{
    int min,temp;
    for (int i=0;i<n-1;i++)
    {
        min = i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
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
  int a[100],n;
  printf("Enter the number of elements : ");
  scanf("%d",&n);
  printf("Enter the elements : ");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }

  sort(a,n);

  printf("Sorted Array ");
  for(int i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }


}