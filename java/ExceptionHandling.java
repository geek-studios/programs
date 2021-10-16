import java.io.*;
import java.util.*;

class Vote{
    void Age(int age)throws IOException
    {
    if(age<18)
     throw new IOException();
    else
     System.out.println("Eligible to vote");
    }
}
class ExceptionHandling {
    public static void main(String[] args)
    {
        int a;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the age");
        a=sc.nextInt();
        try{
            Vote v=new Vote();
            v.Age(a);
        } 
        catch(IOException e){
            System.out.println("Not Eligible to vote");
        }
        finally{
            System.out.println("Verification Complete");
        }
    }
}
/*
Enter the age
10
Not Eligible to vote
Verification Complete
*/