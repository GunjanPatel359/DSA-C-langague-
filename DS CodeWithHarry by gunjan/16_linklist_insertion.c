#include<stdio.h>
#include<stdlib.h>

//structuer of link list
struct node{
    int data;
    struct node*next;
};

//traversal of link list 

void linklist_traversal(struct node*p){
    while(p!=NULL){
        printf("%d \n",p->data);
        p=p->next;
    }
}

//insertion at begining
struct node*insertionatstart(struct node *head,struct node*ptr,int number){
    ptr->next=head;
    ptr->data=number;
    return ptr;
}

//insertion at between 
struct node*insertionatbetween(struct node *head,struct node*ptr,int number,int index){
    struct node*p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    ptr->data=number;
    return head;
}

//insertion at ending
struct node*insertionatend(struct node *head,struct node*ptr,int number){
    struct node*p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->data=number;
    ptr->next=NULL;
    return head;
}

// insertion at node
struct node*insertionatnode(struct node *head,struct node *p,struct node *ptr,int number){
    ptr->next=p->next;
    p->next=ptr;
    ptr->data=number;
    return head;
}

int main(){
    //declaring link list 
    struct node*head=(struct node*)malloc(sizeof(struct node));
    struct node*first=(struct node*)malloc(sizeof(struct node));
    struct node*second=(struct node*)malloc(sizeof(struct node));
    struct node*third=(struct node*)malloc(sizeof(struct node));
    struct node*forth=(struct node*)malloc(sizeof(struct node));

    // linking link list
    head->data=56;
    head->next=first;

    first->data=11;
    first->next=second;

    second->data=17;
    second->next=third;

    third->data=89;
    third->next=forth;

    forth->data=73;
    forth->next=NULL;

    //new node
    struct node*ptr=(struct node*)malloc(sizeof(struct node));

    // head=insertionatstart(head,ptr,90);

    // head=insertionatbetween(head,ptr,13,2);

    // head=insertionatend(head,ptr,45);

    // head=insertionatnode(head,third,ptr,78);
    linklist_traversal(head);
    


}