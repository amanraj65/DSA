#include<stdio.h>
#include<stdlib.h>

struct Class{
    int number;
    char ch;
};

int main(){

    struct Class *new = (struct Class *) malloc(sizeof(struct Class));
    
    new->number = 20;
    new->ch = 'c';



    printf("Number = %d\nCharacter = %c", new->number , new->ch);
    

    return 0;
}