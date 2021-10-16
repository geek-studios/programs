
import java.util.Scanner;
class Paliendrome
{
  public static void main(String[] args)
  {
    String string1 = new String();
    int i,j,temp=0;
    Scanner s = new Scanner(System.in);
    System.out.print("ENTER THE STRING : ");
    string1 = s.nextLine();
    for(i=0,j=string1.length()-1;i<=(j/2);i++,j--)
    {
      if(string1.charAt(i)!=string1.charAt(j))
      {
        temp=1;
      }
    }
    if(temp==0)
    {
      System.out.println(string1+" IS PALLENDROME !!");
    }
    else
    {
      System.out.println(string1+" IS NOT PALLENDROME !!");
    }
  }
}