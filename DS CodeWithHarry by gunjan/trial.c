#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
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


// void right(struct node*r){
//     struct node*l=r;
//     if(l->left!=NULL&&l->right!=NULL){
//         printf("%d ",l->data);
//         l=l->left;
//         left(l);
//         r=r->right;
//         right(r);
//     }else if(l->left!=NULL){
//         printf("%d ",l->data);
//         l=l->left;
//     }else if(l->right!=NULL){
//         r=r->right;
//         right(r);
//     }
//     free(l);
// }

// void left(struct node*l){
//     struct node*r=l;
//     if(l->left!=NULL&&l->right!=NULL){
//         printf("%d ",l->data);
//         l=l->left;
//         left(l);
//         r=r->right;
//         right(r);
//     }else if(l->left!=NULL){
//         printf("%d ",l->data);
//         l=l->left;
//         left(l);
//     }else if(l->right!=NULL){
//         r=r->right;
//         right(r);
//     }
//     free(r);
// }

// struct node*traversal(struct node*p){
//     struct node*n=p;
//     printf("%d ",n->data);
//     if(n->left!=NULL&&n->right!=NULL){
//     struct node*l=n->left;
//     struct node*r=r->right;
//         left(l);
//         right(r);
//         free(l);
//         free(r);
//     }else if(n->left!=0){
//     struct node*l=n->left;
//     left(l);
//     free(l);
//     }else if(n->right!=0){
//     struct node*r=n->right;
//     right(r);
//     free(r);
//     }
// }

void traversal(struct node*root){
    if(root!=NULL){
    printf("%d ",root->data);
    traversal(root->left);
    traversal(root->right);
    free(root);
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

    traversal(p);


    return 0;
}