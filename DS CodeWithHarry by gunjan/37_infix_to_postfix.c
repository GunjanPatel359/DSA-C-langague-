#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    int size;
    char *a;
};

int stacktop(struct stack*p){
    return p->a[p->top];
}

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

char pull(struct stack *ptr){
    if(isempty(ptr)){
        printf("stack is already empty \n");
    }else{
        ptr->top--;
        return ptr->a[ptr->top+1];
    }
}

int precedence(char ch){
    if(ch=='*'||ch=='/')
    return 3;
    else if(ch=='+'|| ch=='-')
    return 2;
    else
    return 0;
}

int isoperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
    return 1;
    else
    return 0;
}

char *infixtopostfix(char* infix){
    struct stack*p=(struct stack*)malloc(sizeof(struct stack));
    p->size = 100;
    p->top = -1;
    p->a = (char * )malloc(p->size*(sizeof(char)));
    char * postfix=(char *)malloc((strlen(infix+1))*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isoperator(infix[i])){
            postfix[j]=infix[i];
            j++;
            i++;
        }else{
            if(precedence(infix[i])>precedence(stacktop(p))){
                push(p,infix[i]);
                i++;
            }else{
                postfix[j]=pull(p);
                j++;
            }
        }
    }
    while(!isempty(p)){
        postfix[j]=pull(p);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char * infix ="a-b+t/6";
    printf("postfix is %s",infixtopostfix(infix));
}