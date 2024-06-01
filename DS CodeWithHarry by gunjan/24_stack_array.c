#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    int *a;
};

int isempty(struct stack*p){
    if(p->top==-1){
        return 1;
    }else{
        return 0;
    }
}

int isfull(struct stack*p){
    if(p->top==p->size-1){
        return 1;
    }else{
        return 0;
    }
}

int main(){

    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
        s->size=6;
        s->top=-1;
        s->a=(int *)malloc(s->size*(sizeof(int)));

    if(isempty(s)){
        printf("stack is empty");
    }else{
        printf("stack is not empty");
    }

    return 0;
}