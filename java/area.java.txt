class Shapes{
int Area(int side){
return (side*side);
}
int Area(int length, int breadth){
return (length*breadth);
}
double Area(double radius){
return (3.14*radius*radius);
}
double Area(double height, double base){
return ((height*base)/2);
}
}
class Areas{
public static void main(String[] args){
Shapes s = new Shapes();
System.out.println("Area of square : "+s.Area(5));
System.out.println("Area of rectangle : "+s.Area(5,10));
System.out.println("Area of circle : "+s.Area(1.5));
System.out.println("Area of triangle : "+s.Area(1.3,2.7));
}
}