import java.util.*;
class Palindrome{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
String pal;
int i=0,length;
System.out.println("\n*** Palindrome checker ***");
System.out.print("Please input a string : ");
pal = sc.nextLine();
length = pal.length();
int temp = length - 1;
int half = length/2;
for(int j=0;j<half;j++){
if(Character.toLowerCase(pal.charAt(j))==Character.toLowerCase(pal.charAt(temp))){
i=1;
}
else{
i=0;
break;
}
temp--;
}
if(i==1){
System.out.print(pal+" is a palindrome\n");
}
else{
System.out.print(pal+" is not a palindrome\n");
}
}
}