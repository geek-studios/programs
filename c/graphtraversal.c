/******************************************************************
      GRAPH TRAVERSALS
                            
                            - Contributed by Sreelakshmi P S
*******************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct node
{
  int vertex;
  struct node* link;
};

struct node a[100];
struct node* headOut=NULL,*tempOut;
int n,top=-1,stack[100];
int front=-1,rear=-1,queue[100];


void push(int item) 
{
    if(top<100)
    {
      top++;
      stack[top]=item;
    }
}


int pop()
{
  int item;
  if(top>-1)
  {
    item=stack[top];
    top--;
  }
  return item;
}


void enqueue(int element)
{
  if(rear==99)
    printf("Queue Full !!");
  else
  {
    if(front==-1)
      front=0;
    rear++;
    queue[rear]=element;
  }
}


int dequeue()
{
  int element;
  if(front==-1)
    printf("\nQueue Empty !!");
  else
  {
    element=queue[front];
    if(front==rear)
    {
      front=-1;
      rear=-1;
    }
    else
      front++;
  }
  return element;
}


struct node* alloc(int v)
{
  struct node* p=(struct node*)malloc(sizeof(struct node));
  p->vertex=v;
  p->link=NULL;
  return p;
}


void create()                               // for creating the graph
{
  int i,v,edges,j;
  struct node *temp,*address;
  printf("\nEnter the no. of vertices :\t");
  scanf("%d",&n);
  printf("\nEnter the vertices (Numbers) :\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&v);
    a[i].vertex=v;
    a[i].link=NULL;
  }
  for(i=0;i<n;i++)
  {
    temp=&a[i];
    printf("\nEnter no. of edges of vertex %d (0 for no edge) :\t",a[i].vertex);
    scanf("%d",&edges);
    j=1;
    while(j<=edges)
    {
      printf("\nEdge %d :\t",j);
      scanf("%d",&v);
      address=alloc(v);
      temp->link=address;
      temp=temp->link;
      j++;
    }
  }

}


int search(int item)       // to search and find whether "item" is already present in the visited list or not
{
  struct node* temp=headOut;
  int flag=0;
  if(headOut == NULL)
    flag=0;
  else
  {
    while(temp!=NULL)
    {
      if(temp->vertex == item)
      {
        flag=1;
        break;
      }
      temp=temp->link;
    }
  }
  return flag;
}


void insert(int item)         // for inserting into the visited list
{
  struct node* address=alloc(item);
  if(headOut == NULL)
  {
    headOut=address;
    tempOut=address;
  }
  else
  {
    tempOut->link=address;
    tempOut=tempOut->link;
  }
}


void dfs()
{
  tempOut=NULL,headOut=NULL;
  struct node *temp;
  int i,item;
  if(a==NULL)
    printf("\nGraph EMPTY !!");
  else
  {
    temp=&a[0];
    push(temp->vertex);
    while(top>-1)
    {
        item=pop();
        for(i=0;i<n;i++)
          if(a[i].vertex==item)
          {
            temp=&a[i];
            break;
          }
        if(search(item)==0)     //if not present in the visited list of nodes
        {
          insert(item);
          while(temp->link != NULL)
          {
            push((temp->link)->vertex);
            temp=temp->link;
          }
        }
      }
  }
}


void bfs()
{
  headOut=NULL,tempOut=NULL;
  struct node* temp;
  int item,i;
  if(a==NULL)
    printf("\nGraph EMPTY !!");
  else
  {
    temp=&a[0];
    enqueue(temp->vertex);
    while(front!=-1 && rear !=-1)
    {
      item=dequeue();
      for(i=0;i<n;i++)
        if(a[i].vertex == item)
        {
          temp=&a[i];
          break;
        }
      if(search(item)==0)
      {
        insert(item);
        while(temp->link != NULL)
        {
          enqueue((temp->link)->vertex);
          temp=temp->link;
        }
      }
    }
  }
}


void display()              // for displaying the traversal order
{
  struct node *temp;
  if(headOut==NULL)
    printf("\nList empty !!");
  else
  {
    temp=headOut;
    printf("\n\nElements :\t");
    while(temp!=NULL)
    {
      printf("%d  ",(temp->vertex));
      temp=temp->link;
    }
  }
}


void main()
{
  int op;
  printf("\n   GRAPH TRAVERSALS");
  printf("\n----------------------\n");
  create();
  printf("\nGraph created SUCCESSFULLY !");
  do
  {
    printf("\n\n\nTRAVERSALS...............");
    printf("\n\n1. Breadth First Search (BFS)");
    printf("\n\n2. Depth First Search (DFS)");
    printf("\n\n3. Exit");
    printf("\n\nEnter your option no. :\t");
    scanf("%d",&op);
    switch(op)
    {
      case 1:     printf("\nBFS............");
                  bfs();
                  display();
                  break;
      case 2:     printf("\nDFS............");
                  dfs();
                  display();
                  break;
      case 3:     printf("\nExiting............\n");
                  break;
      default:    printf("\nInvalid option !!");
    }
  }while(op!=3);
}


/******************************************************************
                      SAMPLE INPUT AND OUTPUT

     GRAPH TRAVERSALS
  ----------------------

  Enter the no. of vertices :     8

  Enter the vertices (Numbers) :
  1
  2
  3
  4
  5
  6
  7
  8

  Enter no. of edges of vertex 1 (0 for no edge) :        3
  Edge 1 :        2
  Edge 2 :        3
  Edge 3 :        8

  Enter no. of edges of vertex 2 (0 for no edge) :        2
  Edge 1 :        4
  Edge 2 :        5

  Enter no. of edges of vertex 3 (0 for no edge) :        2
  Edge 1 :        4
  Edge 2 :        6

  Enter no. of edges of vertex 4 (0 for no edge) :        4
  Edge 1 :        2
  Edge 2 :        3
  Edge 3 :        7
  Edge 4 :        8

  Enter no. of edges of vertex 5 (0 for no edge) :        2
  Edge 1 :        2
  Edge 2 :        7

  Enter no. of edges of vertex 6 (0 for no edge) :        2
  Edge 1 :        3
  Edge 2 :        7

  Enter no. of edges of vertex 7 (0 for no edge) :        3
  Edge 1 :        4
  Edge 2 :        5
  Edge 3 :        6

  Enter no. of edges of vertex 8 (0 for no edge) :        2
  Edge 1 :        1
  Edge 2 :        4

  Graph created SUCCESSFULLY !

  TRAVERSALS...............
  1. Breadth First Search (BFS)
  2. Depth First Search (DFS)
  3. Exit
  Enter your option no. : 1

  BFS............
  Elements :      1  2  3  8  4  5  6  7

  TRAVERSALS...............
  1. Breadth First Search (BFS)
  2. Depth First Search (DFS)
  3. Exit
  Enter your option no. : 2

  DFS............
  Elements :      1  8  4  7  6  3  5  2

  TRAVERSALS...............
  1. Breadth First Search (BFS)
  2. Depth First Search (DFS)
  3. Exit
  Enter your option no. : 3

  Exiting............

*******************************************************************/
