import java.util.*;
class Occurence{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
String str;
char a;
int i=0,length,count=0;
System.out.println("\n*** Occurence checker ***");
System.out.print("Please input a string : ");
str = sc.nextLine();
length = str.length();
System.out.print("Please input a character to be counted : ");
a = sc.nextLine().charAt(0);
for(i=0;i<length;i++){
if(str.charAt(i)==a){
count++;
}
}
System.out.print(a+" occured "+count+" times in "+str+"\n");
}
}