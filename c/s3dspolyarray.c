#include <stdio.h>
int m,n,i,j,k;
struct poly
{
 int coeff;
 int expo;
} x1[10],x2[10],x3[10];
void add_poly()
{
 i=0;
 j=0;
 k=0;
 while((i<m)&&(j<n))
 {
 if(x1[i].expo>x2[j].expo)
 {
 x3[k].coeff=x1[i].coeff;
 x3[k].expo=x1[i].expo;
 i=i+1;
 k=k+1;
 }

 else if(x1[i].expo==x2[j].expo)
 { 

 x3[k].coeff=x1[i].coeff+x2[j].coeff;
 x3[k].expo=x1[i].expo;
 i=i+1;
 j=j+1;
 k=k+1;
 }
 else
 {
 x3[k].coeff=x2[j].coeff;
 x3[k].expo=x2[j].expo;
 j=j+1;
 k=k+1;
 }
 }
 while(i<m)
 {
 x3[k].coeff=x1[i].coeff;
 x3[k].expo=x1[i].expo;
 k=k+1;
 i=i+1;
 }

 while(j<n)
 { 
 x3[k].coeff=x2[j].coeff;
 x3[k].expo=x2[j].expo;
 k=k+1;
 j=j+1;
 }
}
void main()
{

 printf("enter the no.of terms in polynomial 1:");
 scanf("%d",&m);
 printf("enter the data of polynomial 1:\n");
 for(i=0;i<m;i++)
 {
 printf("coefficient:");
 scanf("%d",&x1[i].coeff);
 printf("exponent:");
 scanf("%d",&x1[i].expo);
 }
 printf("\nenter the no.of terms in polynomial 2:");
 scanf("%d",&n);
 printf("enter the data of polynomial 2:\n");
 for(i=0;i<n;i++)
 {
 printf("coefficient:"); 
 scanf("%d",&x2[i].coeff);
 printf("exponent:");
 scanf("%d",&x2[i].expo);
 }

 add_poly();
 printf("\npolynomial 1:");
 for(i=0;i<m;i++)
 {
 if(i==(m-1))
 {
 printf("%d(x^%d)",x1[i].coeff,x1[i].expo);
 continue;
 }
 printf("%d(x^%d)+",x1[i].coeff,x1[i].expo);
 }

 printf("\npolynomial 2:");
 for(i=0;i<n;i++)
 {
 if(i==(n-1))
 {
 printf("%d(x^%d)",x2[i].coeff,x2[i].expo);
 continue;
 } 
 printf("%d(x^%d)+",x2[i].coeff,x2[i].expo);
 }
 printf("\nsum:");
 for(i=0;i<k;i++)
 {
 if(i==(k-1))
 {
 printf("%d(x^%d)",x3[i].coeff,x3[i].expo);
 continue;
 }
 printf("%d(x^%d)+",x3[i].coeff,x3[i].expo);
 }
}