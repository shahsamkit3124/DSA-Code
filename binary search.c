#include<stdio.h>

int main()
{
    int arr[30],n,i,low,high,mid,key;
    printf("ENTER NO OF ELEMENTS: ");
    scanf("%d",&n);
    printf("ENTER ELEMENTS:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("ENTER VALUE TO BE FOUND: ");
    scanf("%d",&key);
    low=0;
    high=n-1;
    mid=(low+high)/2;
    while(low<=high)
    {
        if(arr[mid]<key)
            low=mid+1;
        else if(arr[mid]==key)
        {
            printf("%d found at %d\n",key,mid);
            break;
        }
        else
           high=mid-1;
           mid=(low+high)/2;
    }
    if(low>high)
    {
        printf("%d NOT PRESENT IN THE ARRAY!\n",key);
    }
    return 0;
}


