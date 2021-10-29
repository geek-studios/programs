#include <stdio.h>

main()
{
 char a[50],b[50],co[150],i,k=0;
 printf("Enter string 1 :");
 gets(a);
 printf("\nEnter string 2 :");
 gets(b);
 for(i=0;a[i]!='\0';i++)
 {
     co[k]=a[i];
     k++;
 }
 co[k]=' ';
 k++;
 for(i=0;b[i]!='\0';i++)
 {
     co[k]=b[i];
     k++;
 }
 printf("\n\nConcatenated string :");
 puts(co);
}
