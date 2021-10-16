class Counter{
void count(String message){
try
{
for(int i=0;i<10;i++){
System.out.println(i);
Thread.sleep(1);
}
}catch(Exception e){
System.out.println("Error occures");
}
}
}
class Thread1 extends Thread{
Counter counter;
Thread1(Counter count) {
counter = count;
}
public void run() {
synchronized(counter){
counter.count(getName());
}
}
}
class Test {
public static void main(String args[]){
Counter count = new Counter();
Thread1 _th1 = new Thread1(count);
Thread1 _th2 = new Thread1(count);
_th1.start();
_th2.start();
}
}