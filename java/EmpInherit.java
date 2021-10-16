import java.util.*;

class Employee
{  
  String name;
  int age;
  long phone;
  String address;
  double salary;
  Scanner sc = new Scanner(System.in);

   void setname()
    {    
      System.out.println("The name of Employee is :  ");
      name= sc.nextLine();
    }

  void setage()
    {    
      System.out.println("The age of Employee is :  ");
      age= sc.nextInt();
    }

  void setphone()
    {    
      System.out.println("The Phone Number of Employee is :  ");
      phone= sc.nextLong();
    }

  void setaddress()
    {     
      Scanner sc = new Scanner(System.in);
      System.out.println("The Address of Employee is :  ");
      address= sc.nextLine();
    }

  void setsalary()
    {    
      System.out.println("The salary of Employee is :  ");
      salary= sc.nextDouble();
    }



  void printSalary(int i)
  {    
      System.out.println("The Salary of employee is :  "+i);

   }
  void printdetails()
  {  
     System.out.println("The Name of Employee is :  "+name);
     System.out.println("The Age of Employee is :  "+age);
     System.out.println("The Phone Number of Employee is :  "+phone);
     System.out.println("The Address of Employee is :  "+address);
     System.out.println("The Salary of Employee is :  "+salary);
   }
}


class Officer extends Employee
{
   String sp;
   Scanner sc = new Scanner(System.in);

    void setsp()
    {    
      System.out.println("The Specialization of Employee is :  ");
      sp= sc.nextLine();
      System.out.println("The Specialization of Employee is :  "+sp);
    }
}

class Manager extends Employee
{
   String dep;
   Scanner sc = new Scanner(System.in);

   void setdep()
    {    
      System.out.println("The Department of Employee is :  ");
      dep= sc.nextLine();
     System.out.println("The Department of Employee is :  "+dep);
    }
}

class EmpInherit
    {  
   public static void main ( String[] args)

    {   
      Manager m = new Manager();
      Officer o = new Officer();
      System.out.println("Manager");
      m.setname();
      m.setage();
      m.setphone();
      m.setaddress();
      m.setsalary();
      m.setdep();
      m.printdetails();
     System.out.println();
     System.out.println("********************");
     System.out.println("Officer");
      o.setname();
      o.setage();
      o.setphone();
      o.setaddress();
      o.setsalary();
      o.setsp();
      o.printdetails();
    }

}
/*
Manager
The name of Employee is :  
Pranav
The age of Employee is :  
18
The Phone Number of Employee is :  
78975
The Address of Employee is :  
koratty
The salary of Employee is :  
35000
The Department of Employee is :  
Computer
The Department of Employee is :  Computer
The Name of Employee is :  Pranav
The Age of Employee is :  18
The Phone Number of Employee is :  78975
The Address of Employee is :  koratty
The Salary of Employee is :  35000.0

********************/