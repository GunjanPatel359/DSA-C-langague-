#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    char *a;
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

void push(struct stack *ptr,char val){
    if(isfull(ptr)){
        printf("stack overflow \n");
    }else{
        ptr->top++;
        ptr->a[ptr->top]=val;
    }
}

void pull(struct stack *ptr){
    if(isempty(ptr)){
        printf("stack is already empty \n");
    }else{
        ptr->top--;
        printf("number %c is pulled out \n",ptr->a[ptr->top+1]);
    }
}


int parenthesis(char * exp){
    struct stack *sp;
    sp->size=100;
    sp->top=-1;
    sp->a=(char*)malloc(sp->size*sizeof(char));

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(sp,'(');
        }else if(exp[i]==')'){
            if(isempty(sp)){
                return 0;
            }
            pull(sp);
        }
    }
    if(isempty(sp)){
        return 1;
    }else{
        return 0;
    }
}


int main(){

    char *exp="(8*9)";
    if(parenthesis(exp)){
        printf("the parenthesis is matching");
    }else{
        printf("the stack is not matching");
    }
    return 0;
}