#include <stdio.h>

main()
{
    int num,i,sum=0;
    printf("Enter a number :");
    scanf("%d",&num);
    for(i=1;i<num;i++)
    {
        if(num%i==0)
        sum+=i;
    }
    if(sum==num)
    printf("\n\n\t\t  The number is PERFECT ! ");
    else
    printf("\n\n\t\t  The number is NOT PERFECT !");
}
