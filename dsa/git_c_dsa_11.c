/*

Leetcode 1290 - Convert binary number in a linked list to an integer
To input your own binary digits, place them inside the array arr[] in line 11

Compile with (in case of gcc) $ gcc git_c_dsa_11.c ../github/C-Low-Level-Labs/headers/linked_list.c -I headers

*/
#include <stdio.h>
#include <stdlib.h>
#include "../github/C-Low-Level-Labs/headers/linked_list.h"

int arr[] = {1,0,1,1,0,1,1}; //binary values of nodes. Only fill with 0 or 1

node *create(int *,int); //to create the linked list
int bin_to_int(node *); //to convert the binary values of the nodes into an integer
int main()
{
    int count = sizeof(arr)/sizeof(arr[0]); //number of nodes
    node *head = create(arr,count); //creating the linked list
    traverse_ll(head); //print the linked list

    printf("The integer value is %d\n",bin_to_int(head));
    
    free_ll(&head);
    return 0;
}

int bin_to_int(node *head){
    int value = 0;
    while(head){
        value = (value * 2) + head->val;
        head = head->next;
    }
    return value;
}

node *create(int *arr,int count){
    node *head = NULL;
    node **indirect = &head;
    for(int i=0;i<count;i++){
        node *new_node = malloc(sizeof(*new_node));
        if(!new_node){
            perror("Error");
            return NULL;
        }
        new_node->val = arr[i];
        new_node->next = NULL;

        *indirect = new_node;
        indirect = &new_node->next;
    }
    return head;
}
