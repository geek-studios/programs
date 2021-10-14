//Operations on Queue
#include<stdio.h>
#include<stdlib.h>
int n=3;
int queue[3];
int front=-1,rear=-1,item=0;

void enqueue(){
if(rear>=n){
	printf("Queue is full !\n\n");
}
else{
	printf("Please input the element that you want to insert : ");
	scanf("%d",&item);
	if(front==-1){
		front = 0;
	}
	rear++;
	queue[rear]=item;
	printf("Element Inserted into the Queue !\n\n");
}
}

void dequeue(){
	if(front==-1){
		printf("Queue is empty !\n\n");
	}
	else{
		item = queue[front];
		if(front==rear){
			front=-1;
			rear=-1;
		}
		else{
			front++;
		}
		printf("Element %d Deleted from the Queue !\n\n",item);
	}
}

//jopaul23

void display(){
	if(front==-1){
		printf("Queue is empty !\n\n");
	}
	else{
		int tempfront = front;
		int temprear = rear;
		printf("Queue : ");
		while(temprear>=tempfront){
            printf(" %d ",queue[tempfront]);
            tempfront++;
		}
		printf("\n\n"); 
	}
}

void main(){
	int option,done=0;
	while(done==0){
	printf("Please Choose an option from below (1,2,3,4)\n");
	printf("[1] Enqueue\n");
	printf("[2] Dequeue\n");
	printf("[3] Display\n");
	printf("[4] Exit\n");
	printf("Input your option : ");
	scanf("%d",&option);
    switch(option){
    	case 1 : enqueue();
    	         break;
    	case 2 : dequeue();
    	         break;
    	case 3 : display();
    	         break;
    	case 4 : done=1;
    	         break;
    	default: printf("Wrong Option !\n");
    	         break; 
    }
    }
    printf("Thank you\n");
    exit(0);
}