#include<stdio.h>
int n,m,a[10],b[10],i,j,ch,k;
void main()
{ 
  printf("Enter the Number of Process - ");
  scanf("%d",&n);
  printf("Enter the Memory Size of Process Array\n\n");
  for(i=1;i<=n;i++)
   {
     printf("Enter p%d ",i);
     scanf("%d",&a[i]);
    }
    
  printf("\nEnter the Number of Blocks - ");
  scanf("%d",&m); printf("\n");
  for(i=1;i<=m;i++)
   {
     printf("Enter BlockSize %d - ",i);
     scanf("%d",&b[i]);
   }
  printf("\n");
  
  printf("Enter the Choice \t1.First Fit \t2.Best Fit \t3.Worst Fit \t4.Exit \t");
  scanf("%d",&ch);
  printf("\n");
  if(ch==1)
    firstfit(a,b);
  else if(ch==2)
    bestfit(a,b);
  else if(ch==3)
    worstfit(a,b);
  else
    printf("Have a Nice Day\n");
}
  
  
   void firstfit(int a[] , int b[])
   {
     for(i=1;i<=n;i++)
      {
        for(j=1;j<=m;j++)
         {
           if(a[i]<=b[j])
            {
              b[j]=b[j]-a[i];
              printf("P%d got allocated at %d Block\n",i,j);
              break;
             }
          }
       }
     }
     
    
   void bestfit(int a[] , int b[])
   {
     for(i=1;i<=n;i++)
      {
        for(j=1;j<=m;j++)
         {
           if(a[i]<=b[j])
            {
              for(k=j+1;k<=m;k++)
               {
                if(a[i]<=b[k] && b[k]<=b[j])
                 {
                   j=k;
                  }
                }
               b[j]=b[j]-a[i];
               printf("P%d got allocated at %d Block\n",i,j);
               break;
             }
          }
       }
     }
  
  
    
   void worstfit(int a[] , int b[])
   {
     for(i=1;i<=n;i++)
      {
        for(j=1;j<=m;j++)
         {
           if(a[i]<=b[j])
            {
              for(k=j+1;k<=m;k++)
               {
                if(a[i]<=b[k] && b[k]>=b[j])
                 {
                   j=k;
                  }
                }
               b[j]=b[j]-a[i];
               printf("P%d got allocated at %d Block\n",i,j);
               break;
             }
          }
       }
     }
  
      
