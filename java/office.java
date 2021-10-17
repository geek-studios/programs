import java.util.Scanner;
class Employee
	{
	 String name;
	 int age;
	 long phno;
	 String address;
	 double salary;
	 void print_sal()
	 {
		System.out.println("Salary is:"+salary);
	 }
	 void set(String name,int age,long phno,String address,double salary)
	 {
		 this.name=name;
		 this.age=age;
		 this.phno=phno;
		 this.address=address;
		 this.salary=salary;
	 }
    	 void put()
    	 {
	  	System.out.println("Name:"+name);
		System.out.println("Age:"+age);	
		System.out.println("Phone number:"+phno);
		System.out.println("Address:"+address);
		print_sal();
	}
	}
class Officer extends Employee
	{
	 String sp;
	 void getsp(String sp)
	 {
	  this.sp=sp;
	 }
	 String putsp()
	 {
	  return sp;
	 }
	}
class Manager extends Employee
	{
	 String dept;
	 void getdept(String dept)
	 {
	  this.dept=dept;
	 }
	 String putdept()
	 {
	  return dept;
	 }
 	}

class Office
	{
	 public static void main(String args[])
	 {
	  Scanner obj=new Scanner(System.in);
	  Officer O=new Officer();
	  Manager M=new Manager();
	  Employee E=new Employee();
	  String name;
	  int age;
          long phno;
	  String address;
	  double salary;
	  String sp,dept;

	  System.out.println("Enter Officer's details:");
	  System.out.print("Enter name:");
	  name=obj.nextLine();
	  System.out.println();

	  System.out.print("Enter address:");
	  address=obj.nextLine();
	  System.out.println();
	
	  System.out.print("Enter specialisation:");
	  sp=obj.nextLine();
	  System.out.println();

	  System.out.print("Enter age:");
	  age=obj.nextInt();
	  System.out.println();

	  System.out.print("Enter phone number:");
	  phno=obj.nextLong();
	  System.out.println();

	  System.out.print("Enter salary:");
	  salary=obj.nextDouble();
	  System.out.println();

          O.set(name,age,phno,address,salary);
   	  O.getsp(sp);

	  System.out.println("Officer's details:");
	  O.put();
  	  System.out.println("Specialisation:"+O.putsp());
	  System.out.println();

   	  System.out.println("Enter Manager's details:");
            System.out.print("Enter name:");
	  obj.nextLine();
	  name=obj.nextLine();
	  System.out.println();

	  System.out.print("Enter address:");
	  address=obj.nextLine();
	  System.out.println();

	  System.out.print("Enter department:");
	  dept=obj.nextLine();
	  System.out.println();

	  System.out.print("Enter age:");
	  age=obj.nextInt();
	  System.out.println();
           System.out.print("Enter phone number:");
	  phno=obj.nextLong();
	  System.out.println();

   	  System.out.print("Enter salary:");
	  salary=obj.nextDouble();
	  System.out.println();

   	  M.set(name,age,phno,address,salary);
	  M.getdept(dept);

	  System.out.println("Manager's details:");
	  M.put();
  	  System.out.println("Department:"+M.putdept());
	 }
	}







