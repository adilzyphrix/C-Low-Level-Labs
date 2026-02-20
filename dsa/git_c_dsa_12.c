/*
    LeetCode 24 - Swap nodes in pairs
*/
#include "../github/C-Low-Level-Labs/headers/linked_list.h"
#include <stdio.h>
#include <stdlib.h>
int arr[] = {1,2,3,4,5,6,7,8}; // values of the nodes in the linked list
int k = 2; // value of k

node *create(int *,int);
node *swap_in_pairs(node *,int);
int main()
{
    int count = sizeof(arr)/sizeof(arr[0]); // number of nodes
    node *head = create(arr,count); //creating the list
    traverse_ll(head); //printing the list

    head = swap_in_pairs(head,k);
    traverse_ll(head);

    free_ll(&head);
    return 0;
}

node *swap_in_pairs(node *head,int k){
    if(!head || !head->next || k == 0) return head;
    node *tail = head;
    int no_nodes = 1;
    while(tail->next){
        no_nodes++;
        tail = tail->next;
    }
    k = k % no_nodes;
    if(k == 0) return head;
    tail->next = head;

    node *new_tail = tail;
    for(int i=1;i<=(no_nodes-k);i++) new_tail = new_tail->next;
    node *new_head = new_tail->next;
    new_tail->next = NULL;

    return new_head;
}

node *create(int *arr,int count){
    node *head = NULL;
    node **indirect = &head;
    for(int i=0;i<count;i++){
        node *new_node = malloc(sizeof(*new_node));
        if(!new_node) return NULL;
        new_node->val = arr[i];
        new_node->next = NULL;

        *indirect = new_node;
        indirect = &new_node->next;
    }
    return head;
}
