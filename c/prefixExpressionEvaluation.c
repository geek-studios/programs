//Program to evaluate prefix expression
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char stack[30],prefix[30];
int top=0,pos=0,x,y,result,item,val;
int push(int item){
	if(top<=30){
		top++;
		stack[top]=item;
	}
}
int pop(){
	if(top>-1){
		item = stack[top];
        top = top -1;
        return item;
	}
}
void evaluate(){
   for(int i=0;prefix[i]!='\0';i++){
   	if(isalpha(prefix[i])!=0){
	printf("Please input the value of %c : ", prefix[i]);
	scanf("%d", &val);	
	push(val);
   	}
   	else{
   	    x = stack[top];
   	    pop();
   	    y = stack[top];
   	    pop();   		
   		    
   		    switch(prefix[i]){
   		    	case '+' : result = x + y;break;
   		    	case '-' : result = x - y;break;
   		    	case '*' : result = x * y;break;
   		    	case '/' : result = x / y;break;
   		    	case '^' : result = 1;
   		    	           while(y!=0){
   		    	           	result = result * x;
   		    	           	y = y - 1;
   		    	           }
   		    	           break;
   		    	default : printf("\n");
   		    	          printf("Wrong Arithmetic operator '%c' encountered !\n", prefix[i]);
   		    	          printf("Allowed Arithmetic operators are => + , - , * , / , ^ \n");
   		    	          printf("Exiting the application ...\n");
   		    	          exit(0);
   		    	          break;           
   		    }
   		
   		push(result);
   	}

}
}
void main(){
	printf("\n");		
	printf("Please input the prefix expression : ");
	gets(prefix);
   strrev(prefix);
	printf("\n");	
	evaluate();
	printf("\n");	
	printf("The result after evaluation : %d", stack[top]);	
	printf("\n");		
}