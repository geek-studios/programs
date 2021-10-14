//Random Number generating between given range using Math.random() function
//Vinayak Mali

import java.util.Scanner;

public class GeneratingRandomValue {
    public static void main(String[] args) {
        int min,max,random;
        Scanner input = new Scanner(System.in);
        System.out.print("\nEnter Range for Generating Random Number.");
        System.out.print("\nMinimum : ");
        min = input.nextInt();
        System.out.print("\nMaximum : ");
        max = input.nextInt();
        random = (int)((Math.random()*(max-min))+min);
        System.out.println("Random Number generated between "+min+" and "+max+" is "+random);
    }
}
