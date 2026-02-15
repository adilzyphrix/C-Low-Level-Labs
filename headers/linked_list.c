/* 

All possible basic Linked List operations.
Micro-optimised code.

typedef struct node{
    int val;
    struct node *next;
}node;

node *create_ll(int);
void insert_ll(node **,int);
node *delete_ll(node *,int);
void free_ll(node **);
void traverse_ll(const node *);

*/

#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

node *create_ll(int count){ //create a linked list with nodes valued 10,20,30,...
    node *head = NULL;
    node **indirect = &head;

    for(int i=0;i<count;i++){
        node *new_node = malloc(sizeof(*new_node));
        if(!new_node){
            perror("Error");
            return NULL;
        }
        new_node->val = (i+1)*10;
        new_node->next = NULL;

        *indirect = new_node;
        indirect = &new_node->next;
    }
    return head;
}

void insert_ll(node **head_ref, int x){ //inserting a node of value x into the linked list
    node *new_node = malloc(sizeof(*new_node));
    if(!new_node){
        perror("Error");
        return;
    }
    new_node->val = x;
    node **indirect = head_ref;
    while(*indirect && (*indirect)->val < x)
        indirect = &(*indirect)->next;
    new_node->next = *indirect;
    *indirect = new_node;
}

node *delete_ll(node *head,int x){
    node **indirect = &head;
    while(*indirect){
        node *entry = *indirect;
        if(entry->val == x){
            *indirect = entry->next;
            free(entry);
            entry = NULL;
            return head;
        }
        indirect = &entry->next;
    }
}

void traverse_ll(const node *p){ //printing the linked list
    const node *curr = p;
    while(curr){
        if(curr->next)
            __builtin_prefetch(curr->next,0,3);

        printf("%d\t%p\n",curr->val,(void *)curr->next);
        curr = curr->next;
    }
    printf("\n");
}

void free_ll(node **head_ref){ //freeing the linked list
    if(!head_ref || !(*head_ref)) return;
    node *curr = *head_ref;
    node *next_node;
    while(curr){
        if(curr->next)
            __builtin_prefetch(curr->next,0,1);
        next_node = curr->next;
        free(curr);
        curr = next_node;
    }
    *head_ref = NULL;
}