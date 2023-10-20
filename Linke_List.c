#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

// tanseverasal of nodes in a linked list.
void linkedlistTransversal(struct node *ptr)
{
    while (ptr!= NULL)
    {
        printf("Elemnet = %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// insertion of node at the start of the linked list 
struct node *insertAtfirst(struct node *head, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
// insert the node at the index int he linked list
struct node *InsertInIndex(struct node *head ,int data ,int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i!=index-1)
    {
        p = p -> next;
        i++;
    }
    ptr ->data = data;
    ptr ->next = p->next;
    p -> next = ptr;
    return head;
    
}
// inserrt the node at the end of the linked list
struct node * insertAtend(struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node *p = head;
    while (p->next!=NULL){
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next =NULL;
    return head;
}
// insert the node after a node in a linked list
struct node * insertAfternode(struct node *head,struct node *prevNode, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next =prevNode ->next;
    prevNode ->next = ptr;
    return head;
}
int main()
{
    // deaclaration of nodes
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;
    // dynamic creation of nodes
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    // initalization of nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    linkedlistTransversal(head);
    // head = insertAtfirst(head, 0);
    // linkedlistTransversal(head);
    // head = InsertInIndex(head,34,1);
    // printf(".......................\n");
    // linkedlistTransversal(head);
    return 0;
    // this is a complete linke list program
}