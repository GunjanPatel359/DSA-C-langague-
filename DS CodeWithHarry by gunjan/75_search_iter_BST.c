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
void inorder(struct node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

struct node*searchIter(struct node*root,int key){
    while(root!=NULL){
    if(key==root->data){
        return root;
    }else if(key<root->data){
        root=root->left;
    }else{
        root=root->left;
    }
    }
    
    return NULL;
}
int main(){
    struct node*p=createNode(1,NULL,'n');
    struct node*p1=createNode(2,p,'l');
    struct node*p3=createNode(4,p1,'l');
    struct node*p4=createNode(5,p1,'r');
    struct node*p2=createNode(3,p,'r');
    struct node*p5=createNode(6,p2,'l');
    struct node*p6=createNode(7,p2,'r');

    inorder(p);

    struct node*n=search(p,7);
    printf("\n%d",n->data);
    return 0;
}