import java.util.*;
class NumOfChar {
    public static void main(String args[])
     {
         String str;
         char ch;
         int i,len,count=0;
         Scanner sc = new Scanner(System.in);
         System.out.println("Enter the String ");
         str = sc.nextLine();
         System.out.println("Enter the Char whose repetition should be found ");
         ch = sc.nextLine().charAt(0);
         len = str.length();
         for(i=0;i<len-1;i++)
          {
            if(ch==str.charAt(i))
            {
                count++;
            }
          }
         System.out.println("Number of "+ ch + " in "+ str + " is "+ count);

     }
}
/*
Enter the String
Hello World
Enter the Char whose repetition should be found
l
Number of a in Hello World is 3
*/
