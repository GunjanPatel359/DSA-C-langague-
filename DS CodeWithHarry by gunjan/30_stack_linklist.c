#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};
 
void traversal(struct node*top){
    while(top!=NULL){
        printf("%d \n",top->data);
        top=top->next;
    }
}

int isempty(struct node*p){
    if(p==NULL){
        return 1;
    }else{
        return 0;
    }
}

int isfull(struct node*top){
    struct node*p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }else{
        return 0;
    }
}

struct node*push(struct node*top,int val){
    if(isfull(top)){
        printf("stack overflow");
    }else{
        struct node*p=(struct node*)malloc(sizeof(struct node));
        p->next=top;
        p->data=val;
        top=p;
        return top;
    }
}

struct node*pull(struct node*top){
    if(isempty(top)){
        printf("cannot pull stack is empty");
    }else{
        struct node*p=(struct node*)malloc(sizeof(struct node));
        p=top;
        int x=top->data;
        top=top->next;
        free(p);
        printf("%d \n",x);
        return top;
    }
}

// int pull(struct node**top){
//     if(isempty(*top)){
//         printf("cannot pull stack is empty");
//     }else{
//         struct node*p=(struct node*)malloc(sizeof(struct node));
//         p=*top;
//         int x=(*top)->data;
//         *top=*top->next;
//         free(p);
//         return x;
//     }
// }

int peek(struct node*top,int pos){
    struct node*ptr=top;
    for(int i=0;(i<pos-1&&ptr!=NULL);i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }else{
        return -1;
    }
}

int main(){
    struct node*top=NULL;
    
    top=push(top,56);

    traversal(top);

    // let element=pull(&top);
    // printf("%d",element);

    // top=pull(top);

    printf("%d",peek(top,1));

    traversal(top);
    return 0;
}