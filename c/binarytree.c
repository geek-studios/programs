#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *rchild,*lchild;
}*root=NULL;

void buildtree(struct node *r)
{
 int item;
 char ch;
 printf("\n Does node %d have left subtree?(y/n):",r->data);
 scanf(" %c",&ch);
 if(ch=='y')
 {
  struct node *p;
  p=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter the element:");
  scanf("%d",&item);
  p->data=item;
  p->lchild=NULL;
  p->rchild=NULL;
  r->lchild=p;
  buildtree(p);
 }
 printf("\n Does node %d have right subtree?(y/n):",r->data);
 scanf(" %c",&ch);
 if(ch=='y')
 {
 struct node *p;
  p=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter the element:");
  scanf("%d",&item);
  p->data=item;
  p->lchild=NULL;
  p->rchild=NULL;
  r->rchild=p;
  buildtree(p);
 }
}

struct node *search(struct node *r,int key)
{
 struct node *x=NULL;
 if(r->data==key)
 {
  return r;
 }
 else if(r->lchild!=NULL)
 {
  x=search(r->lchild,key);
 }
 if((x==NULL)&&(r->rchild!=NULL))
 {
  x=search(r->rchild,key);
 }
 return x;
}

void insert()
{
 int key,item;
 char ch;
 printf("\n Enter the parent element:");
 scanf("%d",&key);
 struct node *l,*p;
 l=search(root,key);
 if(l==NULL)
 {
  printf("\n Search Unsuccessfull");
 }
 else if((l->lchild==NULL)||(l->rchild==NULL))
 {
  printf("\n Enter the element to be inserted:");
  scanf("%d",&item);
  p=(struct node*)malloc(sizeof(struct node));
  p->data=item;
  p->lchild=NULL;
  p->rchild=NULL;
  printf("\n Where to insert?Left or Right(L/R):");
  scanf(" %c",&ch);
  if(ch=='L')
  {
   if(l->lchild==NULL)
   {
    l->lchild=p;
    printf("\n Element inserted");
   }
   else
   {
    printf("\n Desired insertion is not possible");
    free(p);
   }
  }
  if(ch=='R')
  {
   if(l->rchild==NULL)
   {
    l->rchild=p;
    printf("\n Element inserted");
   }
   else
   {
    printf("\n Desired insertion is not possible");
    free(p);
   }
  }
 }
 else
 {
  printf("\n Insertion not possible");
 }
}

struct node *parent(struct node *r, struct node *key)
{
 struct node *x = NULL;
 if((r->lchild == key)||(r->rchild==key))
	{
	 return r;
	}
	else if(r->lchild != NULL)
	{
	 x=parent(r->lchild, key);
	}
	if((x==NULL)&&(r->rchild!=NULL))
	{
	 x=parent(r->rchild, key);
	}
	return x;
}

void Delete(int key)
{
 struct node *ptr = search(root, key), *par;
 if(ptr==NULL)
 {
  printf("\n Element not found");
  return;
 }
 if((ptr->lchild!=NULL)||(ptr->rchild != NULL))
 {
  printf("Deletion not possible.");
  return;
 }
 par = parent(root, ptr);
 if(par == NULL)
 {
  root = NULL;
 }
 else if(par->lchild==ptr)
 {
  par->lchild = NULL;
 }
 else
 {
  par->rchild = NULL;
 }
 free(ptr);
 printf("Deletion Successful.");
}

void inorder(struct node *r)
{
  if(r!=NULL)
  {
    inorder(r->lchild);
    printf("%d ",r->data);
    inorder(r->rchild);
  }
}
void preorder(struct node *r)
{
  if(r!=NULL)
  {
    printf("%d ",r->data);
    preorder(r->lchild);
    preorder(r->rchild);
  }
}
void postorder(struct node *r)
{
  if(r!=NULL)
  {
    postorder(r->lchild);
    postorder(r->rchild);
    printf("%d ",r->data);
  }
}
void traverse()
{
  int ch;
  printf("\n  MENU\n1.INORDER\n2.PREORDER\n3.POSTORDER\nENTER YOUR CHOICE: ");
  scanf("%d",&ch);
    switch (ch)
    {
      case 1 : printf("INORDER : ");
              inorder(root);
               break;
      case 2 : printf("PREORDER : ");
                preorder(root);
                break;
      case 3 : printf("POSTORDER : ");
                postorder(root);
                break;
      default : printf("INVALID ENTRY!!");
    }
    printf("\n");
}

void main()
{
 int ch,key,item,n;
 struct node *p,*pos=NULL;
 p=(struct node*)malloc(sizeof(struct node));
 printf("\n Enter the root element:");
 scanf("%d",&item);
 p->data=item;
 p->lchild=NULL;
 p->rchild=NULL;
 root=p;
 buildtree(root);
 do{
 printf("\nMENU \n1.INSERT \n2.SEARCH \n3.DELETE \n4.TRAVERSE \n5.EXIT");
 printf("\n ENTER YOUR CHOICE:");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:insert();
         break;
  case 2:printf("\n Enter the element to be searched:");
         scanf("%d",&key);
         pos=search(root,key);
         if(pos!=NULL)
          printf("\n Element found");
         else
          printf("\n Element not found");
         break;
  case 3:printf("\n Enter the element to be deleted:");
         scanf("%d",&n);
         Delete(n);
         break;
  case 4:traverse();
         break;
  case 5:exit(0);
         break;
 }
 }while(ch!=5);
}