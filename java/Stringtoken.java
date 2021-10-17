import java.io.*;
import java.util.*;

class Stringtoken {
    public static void main(String[] args) {
        String s = new String();
        String temp;

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int sum = 0;
        System.out.println("Enter the integers:");
        try {
            s = reader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        StringTokenizer st = new StringTokenizer(s, " ");
        System.out.println("\nIntegers are : ");
        while (st.hasMoreTokens()) {
            temp = st.nextToken();
            int a = Integer.valueOf(temp);
            System.out.println(a + " ");
            sum += a;
        }

        System.out.println("The sum of the entered Integers is " + sum);

    }
}

/*Enter the integers:
3 5 8 9 10

Integers are :
3
5
8
9
10
The sum of the entered Integers is 35*/