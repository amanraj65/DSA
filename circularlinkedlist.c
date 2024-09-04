#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node * head){
    struct Node * ptr = head;
    do
    {
        printf("Data = %d\n",ptr->data);
        ptr = ptr->next;
    } while (ptr != head);    
}

struct Node * insertAtFirst(struct Node * head, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = head;
    return head;
}

int main(){
    struct Node * head = (struct Node *) malloc(sizeof(struct Node));
    struct Node * second = (struct Node *) malloc(sizeof(struct Node));
    struct Node * third = (struct Node *) malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *) malloc(sizeof(struct Node));

    head ->data = 4;
    head ->next = second;
    second ->data = 3;
    second ->next = third;
    third ->data = 6;
    third ->next = fourth;
    fourth ->data = 1;
    fourth ->next = head;

    printf("Linked list before\n");
    linkedListTraversal(head);
    printf("Linked list after\n");
    head = insertAtFirst(head,20);
    linkedListTraversal(head);

    return 0;
}