public class Matrixprdt 
{
   public static void main(String args[]) 
   {
      int A[][] = { { 1, 2 }, { 3, 4 } };
      int B[][] = { { 1, 2 }, { 3, 4 } };
      int C[][] = new int[2][2];
      int i, j, k;
      System.out.println("1st 2D Array is:");
      for (i = 0; i < 2; i++) 
      {
         for (j = 0; j < 2; j++) 
         {
           System.out.print(A[i][j] + " ");
         }
         System.out.println();
      }
     System.out.println("2nd 2D Array is:");
     for (i = 0; i < 2; i++) 
     {
        for (j = 0; j < 2; j++) 
        {
          System.out.print(B[i][j] + " ");
        }
        System.out.println();
     }
     
     for (i = 0; i < 2; i++) 
     {
        for (j = 0; j < 2; j++) 
        {
           C[i][j] = 0;
           for (k = 0; k < 2; k++) 
           {
             C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
           }
        }
      }

      System.out.println("Resultant 2D Array is:");
      for (i = 0; i < 2; i++) 
      {
          for (j = 0; j < 2; j++) 
          {
             System.out.print(C[i][j] + " ");
          }
             System.out.println();
      }
   }
}