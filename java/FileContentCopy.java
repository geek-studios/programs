import java.util.*; 
import java.io.*; 
class File 
{ 
public static void main(String args[]) 
{ 
try 
{ 
int line; 
FileInputStream inp = new FileInputStream("input.txt"); 
FileOutputStream out = new FileOutputStream("output.txt"); line = inp.read(); 
while(line != -1) 
{ 
char content = (char) line; 
out.write(content); 
System.out.print(content); 
line = inp.read(); 
} 
System.out.print("\n"); 
System.out.println("Copied contents from input file to output file !!!"); inp.close(); 
out.close(); 
} 
catch(FileNotFoundException e) 
{ 
System.out.println("File not found !"); 
} 
catch(IOException e) 
{ 
System.out.println("Something went wrong !"); 
} 
} 
}
