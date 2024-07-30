#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int array[MAX],n;
void insert()
{
    int index,ele,i;
    printf("Enter the index: ");
    scanf("%d", &index);
    if ( index < 0 || index > n){
        printf("Insertion not possible \nError enter index betweek 0 and %d ", n);
    }
    else{
        printf("Enter the element: ");
        scanf("%d", &ele);
        for (i = n ; i >= index ; i--)
        {
            array[i] = array[i-1];
         }
        array[index] = ele;  
        n++;   
    }
}
void delete()
{
    int index,ele,i;
    printf("Enter the index: ");
    scanf("%d", &index);
    if (index > n || index < 0)
    {
        printf("Deletion not possible \nError enter index betweek 0 and %d ", n);
    }
    else
    {
        for ( i = index+1 ; i < n ; i++)
        {
            array[i-1] = array[i];
        }
        n--;
        printf("Element at position %d is deleted" , index);
    }
    
}
void display()
{
    printf("\n*********** Elements of the array ***********");
    for ( int i = 0 ; i<n ; i++)
    {
        printf("\n%d",array[i]);
    }
}

int main(){
    int i, choice;
    printf("\nEnter how many elements(max 100):\t");
    scanf("%d",&n);
    puts("-----------------Enter elements of array-----------------");
    for ( i = 0 ; i<n ; i++)
    {
        printf("Enter element at index %d :" , i);
        scanf("\n%d" , &array[i]);
    }
    while (1)
    {
        puts("\n\n********* ARRAY OPERATIONS ********* ");
    puts("1.INSERTION");
    puts("2.DELETION");
    puts("3.DISPLAY");
    puts("4.EXIT");

    printf("Enter your choice:\t");
    scanf("%d",&choice);
        switch (choice)
        {
        case 1: insert();
            break;
        
        case 2: delete();
            break;

        case 3: display();
            break;
        case 4: 
        printf("************ Thanks for using the program ************");
        exit(0);
            break;
        default: printf("\nPlease check the input");
            break;
        }
    }
}
