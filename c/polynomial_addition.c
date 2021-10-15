/******************************************************************
      POLYNOMIAL ADDITION USING (SINGLY) LINKED LIST
                                              
                              - Contributed by Sreelakshmi P S
*******************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct poly
{
  int coeff;
  int exp;
  struct poly *link;
};
struct poly *start=NULL,*temp, *start1=NULL, *temp1;     // temp1 always point to the last node in reultant polynomial


struct poly* create()                          // for creating polynomials
{
  start=NULL;                                  
  int n,i,coeff,exp;
  struct poly *p;
  printf("\nEnter the no. of terms :\t");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    p=(struct poly *)malloc(sizeof(struct poly));
    printf("\nEnter the coefficient and exponent :\t");
    scanf("%d\t%d",&coeff,&exp);
    p->coeff=coeff;
    p->exp=exp;
    p->link=NULL;
    if(start!=NULL)
    {
      temp->link=p;
      temp=p;
    }
    else
    {
      start=p;
      temp=p;
    }
  }
  return start;
}


void result(int c,int e)                    // for maintaining the resultant polynomial
{
  struct poly *p;
  p=(struct poly *)malloc(sizeof(struct poly));
  p->coeff=c;
  p->exp=e;
  p->link=NULL;
  if(start1!=NULL)
  {
    temp1->link=p;
    temp1=p;
  }
  else
  {
    start1=p;
    temp1=p;
  }
}


void add(struct poly *a,struct poly *b)               // for adding the two polynomials
{
  struct poly *temp1=a, *temp2=b;
  int sum;
  while(temp1!=NULL && temp2!=NULL)
  {
    if(temp1->exp == temp2->exp)
    {
      sum=temp1->coeff + temp2->coeff;
      result(sum,temp1->exp);
      temp1=temp1->link;
      temp2=temp2->link;
    }
    else if(temp1->exp > temp2->exp)
    {
      result(temp1->coeff,temp1->exp);
      temp1=temp1->link;
    }
    else
    {
      result(temp2->coeff,temp2->exp);
      temp2=temp2->link;
    }
  }
  while(temp1!=NULL)
  {
    result(temp1->coeff,temp1->exp);
    temp1=temp1->link;
  }
  while(temp2!=NULL)
  {
    result(temp2->coeff,temp2->exp);
    temp2=temp2->link;
  }
}


void display(struct poly *d,int i)                    // for displaying the polynomials
{
  start=d;
  struct poly *temp1;
  if(start==NULL)
    printf("\nList empty !!");
  else
  {
    if(i!=0)
    {
      temp1=start;
      printf("\nPolynomial  %d :\t",i);
      while(temp1!=NULL)
      {
        printf("%dx^%d  ",(temp1->coeff),(temp1->exp));
        if((temp1->link)!=NULL)
          printf("+  ");
        temp1=temp1->link;
      }
      printf("\n");
    }
    else
    {
      temp1=start;
      printf("\nSum Polynomial :  ");
      while(temp1!=NULL)
      {
        printf("%dx^%d  ",(temp1->coeff),(temp1->exp));
        if((temp1->link)!=NULL)
          printf("+  ");
        temp1=temp1->link;
      }
      printf("\n");
    }
  }
}


void main()
{
  struct poly *a,*b;
  printf("\n\n   POLYNOMIAL ADDITION");
  printf("\n-------------------------");
  printf("\n\n\nCreating polynomial 1.........\n");
  a=create();
  printf("\nCreating polynomial 2.........\n");
  b=create();
  display(a,1);
  display(b,2);
  add(a,b);
  display(start1,0);
}


/*****************************************************************
                    SAMPLE INPUT AND OUTPUT

  
         POLYNOMIAL ADDITION
      ------------------------

Creating polynomial 1.........

Enter the no. of terms :        3
Enter the coefficient and exponent :    10      3
Enter the coefficient and exponent :    20      1
Enter the coefficient and exponent :    30      0

Creating polynomial 2.........

Enter the no. of terms :        2
Enter the coefficient and exponent :    5       2
Enter the coefficient and exponent :    4       1

Polynomial  1 : 10x^3  +  20x^1  +  30x^0
Polynomial  2 : 5x^2  +  4x^1
Sum Polynomial :  10x^3  +  5x^2  +  24x^1  +  30x^0

*****************************************************************/