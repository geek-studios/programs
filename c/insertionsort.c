/*
JOSEPH SHAJU C
S3 CSB
ROLL NO: 03
PROGRAMME: INSERTION SORT
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n,m,j;
    int a[10];
    printf("Enter the no of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int i=1;i<n;i++)
    {
        m=a[i];
        for(j=i-1;j>=0;j--)
        {
            if (m<a[j])
            {
                a[j+1]=a[j];
            }
            else{
                break;
            }
        }
        a[j+1]=m;
    }

    printf("The sorted list is :");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
}

/*
OUTPUT
****************
Enter the no of elements:
4
Enter the elements:
7
1
9
3
The sorted list is :1  3  7  9 
*/