#include <stdio.h>
#include <stdlib.h>

struct link_list{
    int data;
    struct link_list *next;
};

void linklist_traversal(struct link_list *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    struct link_list *head;
    struct link_list *second;
    struct link_list *third;
    head = (struct link_list *)malloc(sizeof(struct link_list));
    second = (struct link_list *)malloc(sizeof(struct link_list));
    third = (struct link_list *)malloc(sizeof(struct link_list));

    head->data = 7;
    head->next=second;

    second->data = 8;
    second->next=third;

    third->data = 9;
    third->next=NULL;

    linklist_traversal(head);

        return 0;
}