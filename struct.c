#include<stdio.h>
#include<stdlib.h>

struct Sample{
    int number;
    char ch;
};

int main(){

    struct Sample *new = (struct Sample *) malloc(sizeof(struct Sample));

    new->number = 20;
    new->ch = 'a';

    printf("Number:%d\n",new->number);
    printf("Character:%c",new->ch);

    return 0;
}