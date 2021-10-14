#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct node *temp, *root = NULL, *newnode, *parent;

int item;

void node_creation()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d", &newnode->data);
    newnode->lchild = newnode->rchild = NULL;
}

void inorder(struct node *ptr) //inorder recursive function
{
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        printf(" %d ", ptr->data);
        inorder(ptr->rchild);
    }
}

void preorder(struct node *ptr) //preorder recursive function
{
    if (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void postorder(struct node *ptr) //postorder recursive function
{
    if (ptr != NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf(" %d ", ptr->data);
    }
}

void search(int d)
{
    int flag = 0;
    temp = root;

    while (temp != NULL)
    {
        if (d == temp->data)
        {
            printf("ITEM FOUND\n");
            flag = 1;
            break; //to stop it from repeating itself "ITEM FOUND"
        }
        else if (d < temp->data)
        {
            temp = temp->lchild;
        }
        else if (d > temp->data)
        {
            temp = temp->rchild;
        }
    }
    if (flag == 0)
    {
        printf("ITEM IS NOT IN THE LIST\n");
    }
}

void del_case1(struct node *p, struct node *t) //deletion of leaf node
{
    if (p->lchild == t)
    {
        p->lchild = NULL;
    }
    else
    {
        p->rchild = NULL;
    }
}

void del_case2(struct node *p, struct node *t) //deletion of node with one child
{
    if (p->lchild == t)
    {
        if (t->lchild == NULL)
        {
            p->lchild = t->rchild;
        }
        else
        {
            p->lchild = t->lchild;
        }
    }
    else
    {
        if (t->lchild == NULL)
        {
            p->rchild = t->rchild;
        }
        else
        {
            p->rchild = t->lchild;
        }
    }
}

struct node *successor(struct node *ptr)
{

    temp = ptr->rchild;
    if (temp != NULL)
    {
        while (temp->lchild != NULL)
        {
            temp = temp->lchild;
        }
    }
    return (temp);
}

void del_case3(struct node *p, struct node *t)
{
    int item_copy;
    struct node *succ_ptr;
    succ_ptr = successor(t);
    item_copy = succ_ptr->data;
    delete (succ_ptr->data);
    t->data = item_copy;
}

void delete (int item)
{
    temp = root;
    int flag = 0;
    while (temp != NULL && flag == 0) //to locate the node to be deleted with its parent node
    {
        if (item < temp->data)
        {
            parent = temp;
            temp = temp->lchild;
        }
        else if (item > temp->data)
        {
            parent = temp;
            temp = temp->rchild;
        }
        else
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("ITEM IS NOT IN THE LIST\n");
    }
    else //to find the three cases
    {
        if ((temp->lchild == NULL) && (temp->rchild == NULL))
        {
            del_case1(parent, temp);
        }
        else if ((temp->lchild != NULL) && (temp->rchild != NULL))
        {
            del_case3(parent, temp);
        }
        else
        {
            del_case2(parent, temp);
        }
    }
}

void insert_node(struct node *t)
{
    while (t != NULL)
    {
        if (newnode->data < t->data)
        {
            parent = t;
            t = t->lchild;
        }
        else
        {
            parent = t;
            t = t->rchild;
        }
    }

    if (parent->data > newnode->data)
    {
        parent->lchild = newnode;
    }
    else
    {
        parent->rchild = newnode;
    }
}

void main()
{
    int op, search_item;
    do
    {
        printf("Enter your choice:\n1.Insert node\n2.Delete node\n3.Traversal\n4.Search\n5.Exit\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            node_creation();
            if (root == NULL)
            {
                root = newnode;
            }
            else
            {
                insert_node(root);
            }
            break;
        case 2:
            printf("Enter the item to be deleted: ");
            scanf("%d", &item);
            delete (item);
            break;
        case 3:
            printf("Inorder Traversal:\n");
            inorder(root);
            printf("\n");
            printf("Preorder Traversal:\n");
            preorder(root);
            printf("\n");
            printf("Postorder Traversal:\n");
            postorder(root);
            printf("\n");
            break;
        case 4:
            printf("Enter the item to be searched: ");
            scanf("%d", &search_item);
            search(search_item);
            break;
        case 5:
            exit(0);

        default:
            break;
        }
    } while (op != 5);
}
