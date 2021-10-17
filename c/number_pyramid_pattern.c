/*
  1 
 2 3 
4 5 6 
*/
#include <stdio.h>
int main()
{
    int rows;
    int num = 1, sps;
    printf("\nEnter the rows of piramid : ");
    scanf("%d", &rows);
    sps = rows - 1;
    for (int i = 1; i <= rows; i++)
    {

        for (int sp = 1; sp <= sps; sp++)
        {
            printf(" ");
        }
        sps = sps - 1;
        for (int k = 0; k < i; k++)
        {
            printf("%d ", num);
            num = num + 1;
        }
        printf("\n");
    }
    return 0;
}