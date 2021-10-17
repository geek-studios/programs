#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL\n");
}
 
// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
// Reverses a given linked list by changing its `.next` pointers and
// its head pointer. Takes a pointer (reference) to the head pointer
void reverse(struct Node** head)
{
    struct Node* previous = NULL;   // the previous pointer
    struct Node* current = *head;   // the main pointer
 
    // traverse the list
    while (current != NULL)
    {
        // tricky: note the next node
        struct Node* next = current->next;
 
        current->next = previous;    // fix the current node
 
        // advance the two pointers
        previous = current;
        current = next;
    }
 
    // fix the head pointer to point to the new front
    *head = previous;
}
 
int main(void)
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct Node* head = NULL;
    for (int i = n - 1; i >=0; i--) {
        push(&head, keys[i]);
    }
 
    reverse(&head);
 
    printList(head);
 
    return 0;
}
