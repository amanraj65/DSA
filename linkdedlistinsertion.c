#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node * next;
};

struct Node * insertAtFirst(struct Node *head , int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;   
}


struct Node * insertAtIndex(struct Node *head , int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    int i=0;
    struct Node * p = head;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p -> next;
    p->next = ptr;
    return head;
}

struct Node * insertAtLast(struct Node * head , int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    while(p->next != NULL){
        p = p->next;
    }
    ptr->data = data;
    ptr -> next = NULL;
    p ->next = ptr;
    return head;
}

struct Node * insertAfterNode(struct Node * head, struct Node * pnode , int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next = pnode->next;
    pnode->next= ptr;
    return head;
}


void traversal(struct Node * ptr){
    while (ptr != NULL)
    {
    printf("data %d\n", ptr -> data);
    ptr = ptr->next;
    }
    
}

int main(){
    struct Node * head = (struct Node *) malloc(sizeof(struct Node));
    struct Node * second = (struct Node *) malloc(sizeof(struct Node));
    struct Node * third = (struct Node *) malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *) malloc(sizeof(struct Node));
    head -> data = 7;
    head -> next = second;

    second -> data = 150;
    second -> next = third;

    third -> data = 220;
    third -> next = fourth;

    fourth -> data = 300;
    fourth -> next = NULL;

    printf("Old List\n");
    traversal(head);

    // printf("New List after insertion\n");
    // head = insertAtFirst(head,20);
    // traversal(head);

    // printf("New List after insertion\n");
    // head = insertAtIndex(head, 40 , 2);
    // traversal(head);

    // printf("New List after insertion\n");
    // head = insertAtLast(head,112);
    // traversal(head);

    printf("New List after insertion\n");
    head = insertAfterNode(head,third,112);
    traversal(head);


    return 0;
}