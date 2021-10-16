/*
Author: chamod dananjaya
Title: practice mathematical problems for beginners!
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void main()
{
    char mo;
    int a;
    int b;
    float answer=0.0;
    float user=0.0;

    srand(time(NULL));


   printf("You can select one from following options,\n\n ");
   printf("\t\t\t + : Addition\n");
   printf("\t\t\t - : Subtraction\n");
   printf("\t\t\t * : Multiplication\n");
   printf("\t\t\t / : Division \n\n");

    printf("Please select a type of mathematical operation that you want.");
    scanf("%s",&mo);

    if (mo=='+'){
        printf("\nEnter the answer for following problem:\n");
        a=rand()%100;
        b=rand()%100;
        answer=a+b;
        printf("\t%d + %d=",a,b);
        scanf("%f",&user);
            if(user==answer){
                printf("\nGood your answer is correct!\n");}
            else{
                printf("Your answer is incorrect\n");
                printf("The correct answer is:%.0f\n",answer);}
        }

    else if (mo=='-'){
        printf("Enter the answer for following problem:\n");
        a=rand()%100;
        b=rand()%100;
        answer=a-b;
        printf("%d - %d=",a,b);
        scanf("%f",&user);
            if(user==answer){
                printf("Good your answer is correct\n");}
            else{
                printf("Your answer is incorrect\n");
                printf("The correct answer is:%.0f\n",answer);}
        }

    else if (mo=='*'){
        printf("Enter the answer for following problem:\n");
        a=rand()%100;
        b=rand()%100;
        answer=a*b;
        printf("%d * %d=",a,b);
        scanf("%f",&user);
            if(user==answer){
                printf("Good your answer is correct\n");}
            else{
                printf("Your answer is incorrect\n");
                printf("The correct answer is:%.0f\n",answer);}
        }

    else if (mo=='/'){
        printf("Enter the answer for following problem:\n");
        a=rand()%100;
        b=rand()%100;
        answer=(float)a/b;
        printf("%d / %d=",a,b);
        scanf("%f",&user);
            if(user==answer){
                printf("Good your answer is correct\n");}
            else{
                printf("Your answer is incorrect\n");
                printf("The correct answer is:%.2f\n",answer);}
        }
    else {
         printf("\nInvalid operation!\n");
    }
}
