/*
JOSEPH SHAJU C
S3 CSB
ROLL NO: 03
PROGRAMME: QUICK SORT
*/

#include <stdio.h>
#include <stdlib.h>

int n;
int a[10];

void quick_sort(int first, int last)
{
    int i, j, pivot;
    int temp;
    if (first < last)
    {
        pivot = a[first];
        i = first;
        j = last;
        while (i < j)
        {
            while (i < last && a[i] <= pivot)
            {
                i++;
            }
            while (j > first && a[j] >= pivot)
            {
                j--;
            }
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                for (int k = 0; k < n; k++)
                {
                    printf(" %d ", a[k]);
                }
                printf("\n");
            }
        }

        temp = a[j];
        a[j] = a[first];
        a[first] = temp;
        for (int k = 0; k < n; k++)
        {
            printf(" %d ", a[k]);
        }
        printf("\n");
        quick_sort(first, j - 1);
        quick_sort(j + 1, last);
    }
}

void main()
{

    printf("Enter the no of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quick_sort(0, n - 1);

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
4
8
5
9
The sorted list is :4  5  7  8  9 
*/