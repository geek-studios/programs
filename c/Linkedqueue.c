#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
}*front=NULL,*rear=NULL,*temp;

void insert()
{
int item;
struct node *p;
p=(struct node*)malloc(sizeof(struct node));
printf("\n Enter the element:");
scanf("%d",&item);
p->data=item;
p->link=NULL;
if((front==NULL)&&(rear==NULL))
{
front=p;
rear=p;
}
else
{
rear->link=p;
rear=p;
}
}

void Delete()
{
if((front==NULL)&&(rear==NULL))
printf("\n***QUEUE EMPTY***");
else
{
temp=front;
printf("\n Deleted element is:%d",temp->data);
if(front==rear)

front=rear=NULL;
else
front=front->link;
free(temp);
}
}

void display()
{
if((front==NULL)&&(rear==NULL))
printf("\n***QUEUE EMPTY***");
else
{
temp=front;
printf("\n Elements in the queue are:\n");
while(temp!=NULL)
{
printf("%d \n",temp->data);
temp=temp->link;
}
}
}

void main()
{
int ch;
printf("\n MENU \n 1.INSERT \n 2.DELETE \n 3.DISPLAY \n 4.EXIT");
do
{
printf("\n ENTER YOUR CHOICE:");
scanf("%d",&ch);

switch(ch)
{
case 1:insert();
break;
case 2:Delete();
break;
case 3:display();
break;
case 4:exit(0);
break;
}
}while(ch!=4);
}