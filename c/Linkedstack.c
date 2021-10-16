#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
}*top=NULL,*temp;

void push()
{
int item;
struct node *p;
p=(struct node*)malloc(sizeof(struct node));
printf("\n Enter the element:");
scanf("%d",&item);
p->data=item;
if(top==NULL)
{
p->link=NULL;
top=p;
}
else
{
p->link=top;
top=p;
}
}

void pop()
{

if(top==NULL)
printf("\n***UNDERFLOW***");
else if(top->link==NULL)
{
temp=top;
printf("\n Deleted element is:%d",temp->data);
top=NULL;
free(temp);
}
else
{
temp=top;
top=temp->link;
printf("\n Deleted element is:%d",temp->data);
free(temp);
}
}

void display()
{
if(top==NULL)
printf("\n***UNDERFLOW***");
else
{
temp=top;
printf("\n Elements in the stack are:\n");
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
printf("\n MENU \n 1.PUSH \n 2.POP \n 3.DISPLAY \n 4.EXIT");
do
{
printf("\n ENTER YOUR CHOICE:");
scanf("%d",&ch);
switch(ch)
{
case 1:push();
break;
case 2:pop();
break;
case 3:display();
break;
case 4:exit(0);
break;
}
}while(ch!=4);
}