#include <stdio.h>

main()
{
    int year;
    printf("Enter year:");
    scanf("%d",&year);
    if(year%4==0)
     {
         if(year%100==0)
         {
            if(year%400==0)
             leap:printf("\n\n\t\t  Its a LEAP YEAR !");
            else 
             goto error;
         }
         else
          goto leap;
     }
    else
     error:printf("\n\n\t\t  Its not a LEAP YEAR");
}
