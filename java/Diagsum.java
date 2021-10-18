import java.util.*;
class Diagsum 
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int A[][] = new int[10][10];
        int m,n,i,j;
        int sum=0;
        System.out.println("Enter the number of rows and columns in the matrix ");
        m = sc.nextInt();
        n = sc.nextInt();
        System.out.println("Enter the elements of the matrix ");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                A[i][j] = sc.nextInt();
        }
        System.out.println("The matrix is");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                System.out.print("  "+A[i][j]);
            }
            System.out.println();
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                {
                    sum=sum+A[i][j];
                }
            }
        }
        System.out.println("Sum of diagonal elements is "+sum);
    }
}
/*   
OUTPUT
Enter the number of rows and columns in the matrix 
3
3
Enter the elements of the matrix 
1
2
3
4
5
6
7
8
9
The matrix is
  1  2  3
  4  5  6
  7  8  9
Sum of diagonal elements is 15
*/