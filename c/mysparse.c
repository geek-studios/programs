/*
JOSEPH SHAJU C
S3 CSB
ROLL NO: 03
PROGRAMME: SPARSE MATRIX
*/

#include<stdio.h>

void main()
{
    int k=1,a[10][10],row,column,b[10][10];
    printf("Enter the number of rows and columns:\n");
    scanf("%d%d",&row,&column);
    b[0][0]=row;
    b[0][1]=column;

    printf("Enter the elements:\n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("The entered array is \n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("%d\t",a[i][j]);
            if(a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
        printf("\n");
    }
    b[0][2]=k-1;
    printf("Sparse representation is \n");
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
}

/*

OUTPUT

Enter the number of rows and columns:
3
3
Enter the elements:
8
0
7
0
1
0
0
0
6
The entered array is 
8       0       7
0       1       0
0       0       6
Sparse representation is 
3       3       4
0       0       8
0       2       7
1       1       1
2       2       6

*/
