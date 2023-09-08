#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;

void insert(int val){
    struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=val;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
        return;
    }
    struct Node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=new_node;
}

void display(){
    struct Node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void reverse_iterative(){
    struct Node* curr=head;
    struct Node* prev=NULL;

    while(curr!=NULL){
        struct Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    head=prev;
}


struct Node* recursive_reverse(struct Node* curr,struct Node* prev){
    if(curr==NULL){
        return prev;
    }
    struct Node* next=curr->next;
    curr->next=prev;

    return recursive_reverse(next,curr);
}

struct Node* middle(struct Node* head){
    if(head==NULL) return NULL;
    struct Node* slow=head;
    struct Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

struct Node* merge(struct Node* a, struct Node* b) {
    struct Node dummy;
    struct Node* res=&dummy;

    while(a!=NULL && b!=NULL){
        if(a->data<=b->data){
            res->next=a;
            a=a->next;
        }
        else{
            res->next=b;
            b=b->next;
        }
        res=res->next;
    }

    while(a!=NULL){
        res->next=a;
        a=a->next;
        res=res->next;
    }

    while(b!=NULL){
        res->next=b;
        b=b->next;
        res=res->next;
    }
    return dummy.next;

}

// Function to perform merge sort on a linked list
struct Node* mergeSort(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* mid = middle(head);

    struct Node* left = head;
    struct Node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main(){
    insert(10);
    insert(20);
    insert(40);
    insert(30);
    insert(60);
    insert(50);
    display();
    head=recursive_reverse(head,NULL);
    display();
    printf("%d\n",middle(head)->data);
    head=mergeSort(head);
    display();

}