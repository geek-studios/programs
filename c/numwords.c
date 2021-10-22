#include <stdio.h>

main()
{
    char str[20];
    int i,n=0;
    printf("\n\t\t   Enter the string:");
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ')
        n++;
    }
    n++;
    printf("\n\n\n\t\t    NO: OF WORDS:%d",n);
    
}
