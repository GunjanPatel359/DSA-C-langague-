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

//incomplete
void isBST(struct node*root){
    static struct node*prev =NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL&&root->data<=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }else{
        return 1;
    }
}

void inorder(struct node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
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

//                   p=6
//              /            \      
//            p1=3           p2=9
//         /      \       /       \
//       p3=1    p4=4   p5=7      p6=11

    inorder(p);
    return 0;
}