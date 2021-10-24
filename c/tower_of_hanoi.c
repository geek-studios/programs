/*
c program for tower_of_hanoi
Author: Anil Kumar
Date modified:23-10-2021
*/

#include <stdio.h>
void tower(char A, char B, char C, int n)
{

    if (n == 1)
    {

        printf("move disk %d from %c to %c \n", n, A, B);
        return;
    }
    else
    {

        tower(A, C, B, n - 1);

        printf("move disk %d from %c to %c \n", n, A, B);
        tower(C, B, A, n - 1);
    }
}

int main()
{

    // char A=A, B=B, C=C;

    int n;

    printf("enter the number of disk:");
    scanf("%d",&n);

    tower('A', 'B', 'C', n);
}
