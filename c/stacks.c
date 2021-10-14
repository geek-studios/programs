/*
    Author: Maheswaran T Parameswaran
    Dept of EEE, S4 

    Date: 14th October 2021
*/

#include <stdio.h>

#define STACK_LENGTH 5
#define STACK_EMPTY -1

int stack[STACK_LENGTH];
int stack_top = STACK_EMPTY;

// Int stack only
void push(int val)
{
    if(stack_top >= STACK_LENGTH)
    {
        printf("Stack overflow \n");
        return;
    }

    stack_top++;
    stack[stack_top] = val;
}

int pop()
{
    if(stack_top == -1)
    {
        printf("Stack empty ");
        return STACK_EMPTY;
    }
    int result = stack[stack_top];
    stack_top--;
    return result;
}

int peek()
{
    if(stack_top == -1)
    {
        printf("Stack Empty ");
        return STACK_EMPTY;
    }
    int result = stack[stack_top];
    return result;
}

void display_all()
{
    for(int i = 0; i <= stack_top; i++)
    {
        printf("%d\n", stack[stack_top - i]);
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    
    // push(6);     // gives stack overflow
    // push(6);
    // push(6);

    
    // display_all();   // prints entire stack

    // printf("%d\n",pop());
    // printf("%d\n",pop());
    // printf("%d\n",pop());
    // printf("%d\n",pop());
    // printf("%d\n",pop());
    return 0;
}