#include <stdio.h>
/*
Formula
    X = √N
    X(i+1) = 1/2(Xi + N/Xi)
*/
// Function to get absolute value of the number given by user.
float absolute(float num)
{
    if(num < 0){
        num = -num;
    }
    return num;
}
// Function to calculate square root of the number using Newton-Raphson method
float square_root(int x)
{
    const float difference = 0.00001;
    float guess = 1.0;
    while(absolute(guess * guess - x) >= difference){
        guess = (x/guess + guess)/2.0;
    }
    return guess;
}

int main()
{
    int number;
    float root;
    printf("Enter a number: ");
    scanf("%i", &number);
    root = square_root(number);
    printf("The square root of %i is: %f", number, root);
    return 0;
}
