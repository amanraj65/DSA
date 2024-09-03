#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void traverse(struct Node * ptr)
{
    while (ptr != NULL)
    {
        printf("Data : %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

struct Node * deleteAtFirst(struct Node * head){
    struct Node * ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

struct Node * deleteAtIndex(struct Node * head, int index)
{
    struct Node * p = head;
    struct Node * q = head ->next;
    int i=1;
    while( i != index-1 ){
        i++;
        p = p->next;
        q = q->next;
    }
    p ->next = q->next;
    free(q);
    return head;
}

struct Node * deleteAtLast(struct Node * head){
    struct Node * p = head;
    struct Node * q = head -> next;
    while ( q ->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p -> next = NULL;
    free(q);
    return head;
}

struct Node * deleteAfterNode(struct Node * head, struct Node * ptr)
{
    struct Node * p = head;
    while (p->next != ptr)
    {
        p = p->next;
    }
    p ->next = ptr ->next;
    free(ptr);
    return head;
}


int main(){
    struct Node * head = (struct Node *) malloc(sizeof(struct Node));
    struct Node * second = (struct Node *) malloc(sizeof(struct Node));
    struct Node * third = (struct Node *) malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *) malloc(sizeof(struct Node));

    head -> data = 10;
    head -> next = second;

    second -> data = 40;
    second -> next = third;

    third -> data = 80;
    third -> next = fourth;

    fourth -> data = 110;
    fourth -> next = NULL;

    // printf("List before\n");
    // traverse(head);
    // printf("List after\n");
    // head = deleteAtFirst(head);
    // traverse(head);

    // printf("List before\n");
    // traverse(head);
    // printf("List after\n");
    // head = deleteAtIndex(head,2);
    // traverse(head);

    // printf("List before\n");
    // traverse(head);
    // printf("List after\n");
    // head = deleteAtLast(head);
    // traverse(head);

    printf("List before\n");
    traverse(head);
    printf("List after\n");
    head = deleteAfterNode(head,second);
    traverse(head);



    return 0;
}