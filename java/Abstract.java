abstract class Shape
{
            abstract void NumberOfSides();
}
class Rectangle extends Shape
{
            void NumberOfSides()
            {
                        System.out.println("Number of sides of Rectangle is : 4");
            }
}
class Triangle extends Shape
{
            void NumberOfSides()
            {
                        System.out.println("Number of sides of Triangle is : 3");
            }
}
class Hexagon extends Shape
{
            void NumberOfSides()
            {
                        System.out.println("Number of sides of Hexagon is : 6");
            }
}
class Abstract
{
            public static void main(String args[])
            {
                        Shape s;
                        s=new Rectangle();
                        s.NumberOfSides();
                        s=new Triangle();
                        s.NumberOfSides();
                        s=new Hexagon();
                        s.NumberOfSides();      
                       
            }
}
/*
Number of sides of Rectangle is : 4
Number of sides of Triangle is : 3
Number of sides of Hexagon is : 6
*/