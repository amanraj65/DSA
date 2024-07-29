#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int a[MAX], top = -1;
void push();
void pop();
void display();
int main(){
    int ch;
    printf("-------------STACK MENU-------------\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. DISPLAY\n");
    printf("4. EXIT");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d" , &ch);
        switch(ch)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\nThanks for using the program");
                exit(0);
            }
            default:
            {
                printf("Wrong choice");
                break;
            }
        }
    }
}

void push()
{
    int data;
    if (top==MAX-1)
    {
        printf("*********----STACK OVERFLOW----********");
    }
    else
    {
        printf("Enter element to be pushed: ");
        scanf("%d", &data);
        top++;
        a[top]=data;
        display();
    }
}

void pop()
{
    if (top == -1)
    {
        printf("*********----STACK UNDERFLOW----********");
    }
    else
    {
        printf("\nPopped element: %d" , a[top]);
        top--;
    }

}

void display()
{
    if (top >= 0)
    {
        printf("\n*********----ELEMENTS----********");
        for (int i = top ; i >= 0 ; i--)
        {
            printf("\n%d", a[i]);
        }
    }
    else
    {
        printf("The stack is empty");
    }
}
