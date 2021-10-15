import java.util.Scanner;
class BinarySearch
{
  public static void main(String[]args)
  {
   Scanner s=new Scanner(System.in);
   System.out.println("Enter the size of array:");
   int n=s.nextInt();
   int a[]=new int [n];
   System.out.println("Sorted array:");
   for(int i=0;i<n;i++)
   {
     System.out.println("Enter the element "+(i+1)+" :");
     a[i]=s.nextInt();
   }
   System.out.println();
   System.out.println("Enter the key to be searched:");
   int key=s.nextInt();
   int low=0,high=n-1;
   int mid=(low+high)/2;
    while(low<high && key!=a[mid])
    {
        if(key<a[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
        mid=(low+high)/2;
    }
    if(key==a[mid])
    {
        System.out.println(key+" is found at position "+a[mid]);
    }
    else
    {
        System.out.println(key+" is NOT FOUND!!");
    }

  }
}