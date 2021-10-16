class asc extends Thread{ 
 public void run(){ 
 ascending(); 
 } 
 void ascending(){ 
 for(int i = 1; i <= 10 ; i++){ 
 System.out.println(getName()+" : "+i);  } 
 } 
} 
class desc extends Thread{ 
public void run(){ 
descending(); 
} 
void descending(){ 
for(int j = 10; j >= 1 ; j--){ 
System.out.println(getName()+" : "+j); } 
} 
} 
class multithread{ 
public static void main(String Args[]){ asc a = new asc(); 
desc b = new desc(); 
a.setName("Thread 1"); 
b.setName("Thread 2"); 
a.start(); 
b.start(); 
} 
}
