#include <stdio.h>
int item;
int  pos,i;
struct node
      {
        int data;
        struct node*next,*prev;    
       };
    struct node*p,*start,*head,*tail,*a,*b,*temp;
void insertbeg()
{
    p=(struct node*)malloc(sizeof(struct node));
    printf("enter the element:");
    scanf("%d",&item);
    p->data=item;
    p->next=head;
    if(head!=NULL)
     head->prev=p;
    else
     tail=p;
    head=p;
    p->prev=NULL;   
    
}
void insertend()
{
    p=(struct node*)malloc(sizeof(struct node));
    printf("enter the element:");
    scanf("%d",&item);
    p->data=item;
    p->prev=tail;
    if(tail!=NULL)
       tail->next=p;
    else
         head=p;
    p->next=NULL;
    tail=p;
    if((head==NULL)&&(tail==NULL))
         {
           head=p;
           tail=p;
         }
}

void insertpos()
{
  p=(struct node*)malloc(sizeof(struct node));
  printf("enter the element:");
  scanf("%d",&item);
  p->data=item;
  printf("enter the position to which you want to add the element:");
  scanf("%d",&pos);
  if(pos==1)
    {
      p->data=item;
      p->next=head;
      if(head!=NULL)
         head->prev=p;
      else
         tail=p;
      head=p;
      p->prev=NULL;    
    } 
  else
    { p->data=item;
      a=head;
      for(i=1;i<(pos-1);i++)
         {
           a=a->next;
         }
      b=a->next;
      p->prev=a;
      p->next=b;
      a->next=p;
      b->prev=p; 
    }       
}
void deletebeg()
{
 if(head!=NULL)
 {
   p=head;
   printf("deleted element is:%d",p->data);
     if(head!=tail)
        {
          head=head->next;
          head->prev=NULL;
        }
     else
       {
        head=NULL; 
        tail=NULL;
       }
   free(p);
  }
  else
      printf("empty list!!!");
}
void deleteend()
{
 if(tail!=NULL)
     {
       p=tail;
       printf("deleted element is:%d",p->data);
       if(head!=tail)
         {
          tail=tail->prev;
          tail->next=NULL;
         }
       else
          {
            head=NULL;
            tail=NULL;
          }
       free(p);
    }
  else 
        printf("empty list!!!");      
}
void deletepos()
{
 if(head!=NULL)
   {
     printf("\nenter the position of the element you want to delete:");
     scanf("%d",&pos);
     if(pos!=1)
       {
         a=head;
         for(i=1;i<pos-1;i++)
             {
              a=a->next;     
             }
         b=a->next;
         a->next=b->next;
         b->next->prev=a;
         printf("deleted element is:%d",b->data);
         free(b);   
       }
      else
         deletebeg();
   
  }
  else
  printf("empty list!!!");
}
void displayforward()
{
    if(head==NULL)
    {
    printf("The linked list is empty\n");
    }
    else
    {
    printf("The linked list is\n");  
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    }
}

void displaybackward()
{
    if(tail==NULL)
    {
    printf("The linked list is empty\n");
    }
    else
    {
    printf("The linked list is\n");  
    temp=tail;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->prev;
    }
    }
}
int main()
{
    int ch;
    char c;
     printf("DOUBLY LINKED LIST ");
     do
     {
     printf("\nMENU\n");
     printf("1.insert at the beginning \n");
     printf("2.insert at the end\n");
     printf("3.insert at a given position\n");
     printf("4.delete at the beginning\n");
     printf("5.delete at the end\n");
     printf("6.delete at a given position\n");
     printf("7.display from forward \n");
     printf("8.display from backward \n");
     printf("enter your choice\n");
     scanf("%d",&ch);
     switch(ch)
      {
        case 1: insertbeg();
                break;
        case 2:insertend();
               break;
        case 3:insertpos();
               break;
        case 4:deletebeg();
               break;
        case 5:deleteend();
               break;
        case 6:deletepos();
               break;
        case 7:displayforward();
               break;
        case 8:displaybackward();
                 break;
       default:printf("error!!");
               break;
      }
       printf(" \ndo you want to continue?");
       scanf("%s",&c);
    }while((c=='Y')||(c=='y'));

    return 0;
}

    
