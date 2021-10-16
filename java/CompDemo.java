class Complex {
    double real;
    double imaginary;
    Complex(double i,double j) {
        real = i;
        imaginary = j;
    }
    
    Complex() {
    }

    Complex Add(Complex c) {
        Complex temp = new Complex();
        temp.real = c.real + real;
        temp.imaginary = c.imaginary + imaginary; 
        return temp;
    }
}
class CompDemo {
    public static void main(String args[]) {
        Complex comp = new Complex(2,3);
        Complex comp2 = new Complex(4,5);
        Complex comp3;
        comp3=comp.Add(comp2);
        System.out.println("Reak Part is : "+comp3.real);
        System.out.println("Complex Part is : "+comp3.imaginary);

    }
}
