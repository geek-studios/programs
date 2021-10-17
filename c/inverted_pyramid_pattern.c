/*
*****
****
***
**
*
*/
#include <stdio.h>
int main()
{

    int a;

    printf("Enter the height of the piramid : ");
    scanf("%d", &a);

    for (int i = a; i > 0; i--)
    {

        for (int j = 0; j < i; j++)
        {
            printf("*");
            
        }
        printf("\n");
    }
}