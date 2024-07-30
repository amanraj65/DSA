#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

int isFull() {
  if ((rear + 1) % SIZE == front) {
    return 1;
  } else {
    return 0;
  }
}

int isEmpty() {
  if (front == -1) {
    return 1;
  } else {
    return 0;
  }
}

void enqueue(int data) {
  if (isFull()) {
    printf("Queue Overflow\n");
  } else {
    if (front == -1) {
      front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = data;
    printf("%d enqueued to queue\n", data);
  }
}

int dequeue() {
  int data;
  if (isEmpty()) {
    printf("Queue Underflow\n");
    return -1;
  } else {
    data = queue[front];
    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % SIZE;
    }
    printf("%d dequeued from queue\n", data);
    return data;
  }
}

void display() {
  int i;
  if (isEmpty()) {
    printf("Queue is empty\n");
  } else {
    printf("Queue elements are: ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", queue[i]);
    }
    printf("%d ", queue[rear]);
    printf("\n");
  }
}

int main() {
  int choice, data;
  while (1) {
    printf("\nQueue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter data to enqueue: ");
        scanf("%d", &data);
        enqueue(data);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}