#include<stdio.h>
int i,j,k,m,n,temp,a[50],b[50],c[50],size,loc,min;
void bubsort(int x[20],int s)
   {
    printf("\nTHE ARRAY BEFORE SORTING IS:");
    for (i = 0; i < s; i++)
        printf(" %d ",x[i]);
    printf("\n");
     for(i=0;i<s-1;i++)
        {
          for(j=0;j<s-i-1;j++)
             {
              if(a[j]>a[j+1])
                {
                  temp=a[j];
                  a[j]=a[j+1];
                  a[j+1]=temp;
                }
             }
          for(n=0;n<s;n++)
            {
                printf("%d",a[n]);
            }
                printf("\n"); 
          
        }
        printf("\n the sorted array is:");
        for(i=0;i<s;i++)
           {
             printf(" %d ",a[i]);
           }
   }
void selectsort(int x[20],int s)
    {
      printf("\nTHE ARRAY BEFORE SORTING IS\n");
      for (i = 0; i < s; i++)
        printf(" %d ", x[i]);
      printf("\n");
      for(i=0;i<s-1;i++)
         {
           loc=i;
           min=a[i];
           for(k=i+1;k<s;k++)
              {
                if(a[k]<min)
                  {
                   min=a[k];
                   loc=k;
                  }
              }
           if(loc!=i)
              {
                temp=a[loc];
                a[loc]=a[i];
                a[i]=temp;
              }
             for(n=0;n<s;n++)
            {
                printf("%d",a[n]);
            }
                printf("\n");
         }
      printf("\n the sorted array is");
      for(i=0;i<s;i++)
           {
             printf(" %d",a[i]);
           }
    }
void insertsort(int x[20],int s)
    {
      printf("\nTHE ARRAY BEFORE SORTING IS\n");
    for (i = 0; i < s; i++)
        printf("%d\t", x[i]);
    printf("\n");
     for(i=1;i<s;i++)
        {
         m=a[i];
         for(j=i-1;j>=0;j--)
            {
              if(m<a[j])
                {
                  a[j+1]=a[j];
                }
              else
                  break;
            }
           a[j+1]=m;
           
         for(n=0;n<s;n++)
            {
                printf("%d",a[n]);
            }
                printf("\n"); 
        }
     printf("\n the sorted array is");
      for(i=0;i<s;i++)
           {
             printf(" %d",a[i]);
           }
    }
int main()
{
    int ch;
    printf("enter the size of the array:");
    scanf("%d",&size);
    printf("\n enter the elements:");
    for(i=0;i<size;i++)
       {
         scanf("%d",&a[i]);
       }
    for(i=0;i<size;i++)
      {
        b[i]=a[i];
        c[i]=a[i];      
      }
    
    do
    {
    
    printf("\nSORTING MENU");
    printf("\n1.Bubble Sort");
    printf("\n2.Selection Sort");
    printf("\n3.Insertion Sort");
    printf("\n4.Exit");
    printf("\n enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
          {
            case 1:bubsort(a,size);
                   break;
            case 2:selectsort(b,size);
                   break;
            case 3:insertsort(c,size);
                   break;
            case 4:exit(0);
            default:printf("error!!");
                    break;
          }
    }
    while(ch!=4);
        return 0;
}