#include<stdio.h>
#include<stdlib.h>
int A[100],pos,n;

void lsearch(int key)
{
 int i=0,flag=0;
 while((i<n)&&(flag==0))
 {
  if(A[i]==key)
  {
   flag=1;
   pos=i+1;
  }
  i++;
 }
 if(flag==1)
 printf("\n Element %d found at position %d",key,pos);
 else
 printf("\n Element not found");
}

void binsearch(int key)
{
 int low=0,high=n-1,mid,i;
 mid=(low+high)/2;
 while((key!=A[mid])&&(low<high))
 {
  if(key>A[mid])
  low=mid+1;
  else
  high=mid-1;
  mid=(low+high)/2;
 }
 if(key==A[mid])
 printf("\n Element %d found at position %d",key,mid+1);
 else
 printf("\n Element not found");
}

void sort()
{
 int i,j,temp;
 for(i=0;i<n;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(A[j]>A[j+1])
   {
    temp=A[j];
    A[j]=A[j+1];
    A[j+1]=temp;
   }
  }
 }
 printf("\n Array after sortion:");
 for(i=0;i<n;i++)
 {
  printf("%d \t",A[i]);
 }
}

void main()
{
 int i,key,ch;
 printf("Enter the number of elements:");
 scanf("%d",&n);
 printf("\n Enter elements of the array:");
 for(i=0;i<n;i++)
 {
  scanf("%d",&A[i]);
 }
 printf("\n Elements of the array are:");
 for(i=0;i<n;i++)
 {
  printf("%d \t",A[i]);
 }
 printf("\n MENU \n1.LINEAR SEARCH \n2.BINARY SEARCH \n3.EXIT");
 do{
 printf("\n Enter your choice:");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:printf("\n Enter the element you want to search:");
         scanf("%d",&key);
         lsearch(key);
         break;
  case 2:sort();
         printf("\n Enter the element you want to search:");
         scanf("%d",&key);
         binsearch(key);
         break;
  case 3:exit(0);
         break;
 }
 }while(ch!=3);
}