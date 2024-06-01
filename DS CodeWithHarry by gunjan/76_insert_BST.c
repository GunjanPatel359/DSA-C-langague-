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

void insert(struct node*root,int key){
    struct node*prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            return ;
        }else if(key<root->data){
            root=root->left;
        }else{
            root=root->right;
        }
    }
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->left=NULL;
    new->right=NULL;
    new->data=key;
    if(key<prev->data){
        prev->left=new;
    }else{
       prev->right=new; 
    }
}

int main(){
    struct node*p=createNode(6,NULL,'n');
    struct node*p1=createNode(3,p,'l');
    struct node*p3=createNode(1,p1,'l');
    struct node*p4=createNode(4,p1,'r');
    struct node*p2=createNode(9,p,'r');
    struct node*p5=createNode(7,p2,'l');
    struct node*p6=createNode(11,p2,'r');


    insert(p,8);
    inorder(p);
    return 0;
}