/*
    Author: Maheswaran T Parameswaran
    Dept of EEE, S4 

    Date: 14th October 2021
*/


#include <stdio.h>
#include <stdlib.h>
#define true 1

typedef struct Node node_t;

struct Node {
    int val;
    struct Node* next;
};

void printLinkedList(node_t* head)
{
    node_t* temp = head;
    while(temp != NULL)
    {
        printf("%d->", temp->val);
        temp = temp->next;
    }
    printf("END\n");
}

node_t* createNode(int val)
{
    node_t* newNode = malloc(sizeof(node_t));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

node_t* addToHead(node_t* head, node_t* newNode)
{
    newNode->next = head;
    return newNode;
}

void addToTail(node_t* head, node_t* tail)
{
    node_t* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = tail;
    return;
}

void insertAfterElement(node_t* head, int afterVal, node_t* newNode)
{
    node_t* temp = head;
    while(temp->val != afterVal)
    {
        temp = temp->next;
    }
    node_t* tempAfter = temp->next;
    temp->next = newNode;
    newNode->next = tempAfter;
}

void insertBeforeElement(node_t* head, int beforeVal, node_t* newNode)
{
    node_t* temp = head;
    while(temp->val != beforeVal)
    {
        if(temp->next->val == beforeVal)
            break;
        temp = temp->next;
    }
    node_t* tempBefore = temp->next;
    temp->next = newNode;
    newNode->next = tempBefore;
}

node_t* findNode(int val, node_t* head)
{
    node_t* temp = head;
    while(temp->val != val)
    {
        temp = temp->next;
    }
    return temp;
}

int main()
{
    node_t* head;
    
    node_t* n1 = createNode(10);
    node_t* n2 = createNode(20);
    node_t* n3 = createNode(30);
    node_t* n4 = createNode(50);
    node_t* n5 = createNode(100);

    head = n1;
    n1->next = n2;
    n2->next = n3;

    printLinkedList(head);

    head = addToHead(head, n4);

    printLinkedList(head);

    addToTail(head, n5);

    printLinkedList(head);

    insertAfterElement(head, 50, createNode(66));

    printLinkedList(head);

    insertBeforeElement(head, 30, createNode(45));

    printLinkedList(head);

    // free memory
    
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return 0;
}