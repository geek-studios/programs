class sort
{


      public static void main(String[ ]args)
      {
        int [] a = {5,4,3,2,1};
        int b = 0;

        System.out.println("ARRAY BEFORE SORTING: ");
        for (int i = 0; i < a.length; i++)
         {
           System.out.print(a[i] + " ");
         }

        for (int i = 0; i < a.length; i++)
         {
           for (int j = i+1; j < a.length; j++)
            {
             if(a[i] > a[j])
              {
                b = a[i];
                a[i] = a[j];
                a[j] = b;
              }
         }
     }

     System.out.println("\nARRAY AFTER SORTING IN ASCENDING ORDER: ");
     for (int i = 0; i < a.length; i++)
     {
         System.out.print(a[i] + " ");
     }
   }

}