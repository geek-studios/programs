/*
JOSEPH SHAJU C
S3 CSB
ROLL NO: 03
PROGRAMME: SELECTION SORT
*/

#include <stdio.h>
#include <stdlib.h>


void main()
{
    int a[10],n;
    int loc,min;
    int temp;
    printf("Enter the no of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int i=0;i<n-1;i++)
    {
        loc=i;
        min=a[i];
        for(int k=i+1;k<n;k++)
        {
            if (a[k]<min)
            {
                min=a[k];
                loc=k;
            }
        }
       if (loc!=i)
       {
           temp=a[loc];
           a[loc]=a[i];
           a[i]=temp;
       }
       
    }

    printf("The sorted list is :");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
}

/*
OUTPUT
***************
Enter the no of elements:
5
Enter the elements:
7
1
8
5
4
The sorted list is :1  4  5  7  8
*/