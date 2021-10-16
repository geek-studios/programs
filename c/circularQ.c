#include <stdio.h>

int cq[50];
int front=-1,rear=-1;
int size,item,next,i;

void encqueue()
{
    printf("enter the element\n");
    scanf("%d",&item);
    if(front==(rear+1)%size)
    {
        printf("queue is empty\n");
    }
    if(front==-1)
    {
        front=0;
        rear=0;
        cq[rear]=item;
    }
    else
    {
        next=(rear+1)%size;
        if(next!=front)
        {
            rear=(rear+1)%size;
            cq[rear]=item;
        }
        else
        {
            printf("circular queue is full");
        }
        
    }
}

void decqueue()
{
    if(front==-1)
    {
        printf("circular queue is empty\n");
    }
    else
    {
        item=cq[front];
        printf("deleted element is %d \n",item);
        if(front=rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front%size)+1;
        }
    }
}

void display()
{
    int i;
    if(front==-1)
       printf("circular queue is empty\n");
    else
    {
      for(i=front;i<rear;i++)
        printf("%d/n",cq[i]);
    }
}

void main()
{
    int choice;
    printf("enter the size of the circular queue\n");
    scanf("%d,&size");
    printf("MENU\n");
    printf("1:TO ENTER AN ELEMENT\n");
    printf("2:TO DELETE AN ELEMNT\n");
    printf("3:TO DISPLAY THE ELEMENTS\n");
    printf("4:EXIT");
    do
    {
    printf("ENTER YOUR CHOICE\n");
    scanf("%d",&choice);
    switch(choice)   
    {  
      case 1 : encqueue();
               break;
      case 2 : decqueue();
               break;
      case 3 : display();
               break;
      case 4 : exit(0);
      default : printf("\nINVALID ENTRY!!");
    }
  } while(choice!=4);
 }