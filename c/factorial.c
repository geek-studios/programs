#include <stdio.h>
int fact(int f);
void main()
{
  int n,f;
  printf("\nEnter the number to take factorial : ");
  scanf("%d",&n);
  f=fact(n);
  printf("\n\n\n\t\t   FACTORIAL =%d",f);
}
int fact(int n)
{
  int f;
  if((n==1)||(n==0))
  {
    return 1;  
  }
  else
  {
      f=n*fact(n-1);
      return f;
  }
}
