#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node*createNode(int data,struct node*previous,char direction){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    if(direction=='l'){
        previous->left=n;
    }else if(direction=='r'){
        previous->right=n;
    }
    return n;
}
void preorder(struct node*root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct node*p=createNode(1,NULL,'n');
    struct node*p1=createNode(2,p,'l');
    struct node*p3=createNode(4,p1,'l');
    struct node*p4=createNode(5,p1,'r');
    struct node*p2=createNode(3,p,'r');
    struct node*p5=createNode(6,p2,'l');
    struct node*p6=createNode(7,p2,'r');

    preorder(p);
    return 0;
}