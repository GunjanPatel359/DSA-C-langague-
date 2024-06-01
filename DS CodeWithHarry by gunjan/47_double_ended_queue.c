#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

    struct node *f = NULL;
    struct node *r = NULL;

void linklist_traversal(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueuerare(int val) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Queue is full");
    } else {
        n->data = val;
        n->next = NULL;
        if (f == NULL) { 
            f = n;
            r = n;
        } else {
            r->next = n;
            r = n;
        }
    }
}

// int dequeuerare() {
//     struct node *n;
//     n=f;
//     int a=-1;
//     if (f == NULL) {
//         printf("Queue is empty");
//     } else {
//         while(n->next!=r){
//             n=n->next;
//         }
//         a=r->data;
//         free(r);
//         r=n;
//         r->next=NULL;
//     }
//         return a;     
// }

int dequeuerare() {
    if (f == NULL) {
        printf("Queue is empty");
        return -1; // Or some other error code
    }

    struct node *n = f;
    int a = -1;

    while (n->next != r) {
        n = n->next;
    }

    a = r->data;
    free(r);
    r = n;
    r->next = NULL;

    return a;
}

int dequeuefront() {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    int a=-1;
    if (f == NULL) {
        printf("Queue is empty");
        free(n);
        return -1;
    } else {
        a=f->data;
        n=f;
        f=f->next;
        free(n);
        return a;
    }
}

void enqueuefront(int val) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Queue is empty");
    } else {
        n->data=val;
        n->next=f;
        f=n;
    }
}

int main() {
    enqueuerare(37);
    enqueuerare(56);
    enqueuerare(78);
    // linklist_traversal(f);
    // enqueuefront(13);
    linklist_traversal(f);
    // printf("%d \n",dequeuefront());
    // linklist_traversal(f);
    printf("%d \n",dequeuerare());
    linklist_traversal(f);
    return 0;
}
