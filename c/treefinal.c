#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *lchild, *rchild;
};

struct node *root = NULL;


void inorder(struct node *r)
{
	struct node *ptr = r;
	if(ptr != NULL)
{
		inorder(ptr->lchild);
		printf("%d  ", ptr->data);
		inorder(ptr->rchild);
	}
}

void preorder(struct node *r)
       {
	struct node *ptr = r;
	if(ptr != NULL)
         {
		printf("%d  ", ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

void postorder(struct node *r){
	struct node *ptr = r;
	if(ptr != NULL){
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d  ", ptr->data);
	}
}

void insert(struct node *r)
{
	int ch, item;
	printf("Enter 1 if [%d]: has a left child:  ", r->data);
	scanf("%d", &ch);
	if(ch == 1)
	{
		struct node *n = malloc(sizeof(struct node));
		printf("Enter Data: ");
		scanf("%d", &item);
		n -> data = item;
		n -> lchild = NULL;
		n -> rchild = NULL;
		r -> lchild = n;
		insert(n);
	}
	printf("Enter 1 if [%d]: has a right child:  ", r->data);
	scanf("%d", &ch);
	if(ch == 1)
	{
		struct node *n = malloc(sizeof(struct node));
		printf("Enter Data: ");
		scanf("%d", &item);
		n -> data = item;
		n -> lchild = NULL;
		n -> rchild = NULL;
		r -> rchild = n;
		insert(n);
	}
}

void main()
{
	int n, ch;
	printf(" Binary Tree");

			
			printf("\n\n Creating Binary Tree ");
			printf("\nEnter Root Element: ");
			scanf("%d", &n);
			x=(struct node*)malloc(sizeof(struct node));
			x->data = n;
			x->lchild = NULL;
			x->rchild = NULL;
			root = x;
			insert(root);

		printf("\n1 Traverse 2 Exit");
		scanf("%d", &ch);
             
		switch(ch)
		{
			
			case 1:
			{
				printf("\n1. Inorder  2. Preorder  3. Postorder");
				scanf("%d", &ch);
				switch(ch)
				{
					case 1: inorder(root); 
					break;
					case 2: preorder(root);
					break;
					case 3: postorder(root); 
					break;
				}
				break;
			}
			
			case 2:
			{
			    printf("Exiting Program");
			    exit(0);
			    break;
			}
			default:
			{
			    printf("Invalid entry");
                            break;
			}
		}
	}
}
