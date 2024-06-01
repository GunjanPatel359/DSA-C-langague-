#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
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

void push(struct stack *ptr,int val){
    if(isfull(ptr)){
        printf("stack overflow \n");
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

void pull(struct stack *ptr){
    if(isempty(ptr)){
        printf("stack is already empty \n");
    }else{
        ptr->top--;
        printf("number %d is pulled out \n",ptr->arr[ptr->top+1]);
    }
}

int peek(struct stack* p,int i){
    if(p->top-i+1<0){
        printf("not a valid position");
        return -1;
    }else{
        return p->arr[p->top-i+1];
    }
}

int main(){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*(sizeof(int)));

    push(sp,10);
    push(sp,13);
    push(sp,32);
    push(sp,67);
    pull(sp);

    for(int i=1;i<=sp->top+1;i++){
        printf("%d \n",peek(sp,i));
    }

    return 0;
}