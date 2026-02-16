/*

Leetcode 234 - Palindrome linked list.
Compile with (in case of gcc) $ gcc git_c_dsa_10.c ../github/C-Low-Level-Labs/headers/linked_list.c -I headers

*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../github/C-Low-Level-Labs/headers/linked_list.h"

int arr[] = {1,2,3,4,3,2,1}; //value of the nodes in the linekd list. arr has been declared in "linked_list.h" file
node *create(int *); //creating the linked list
bool is_palindrome(node *);
int main()
{
    node *head = create(arr); //linked list created
    
    bool ans = is_palindrome(head);
    if(ans) printf("The linked list IS palindrome\n");
    else printf("The linked list is NOT palindrome\n");
    
    free_ll(&head);
    return 0;
}

bool is_palindrome(node *head){
    if(!head->next) return true; //only one node
    node *slow = head;
    node *fast = head;
    while(fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    } //slow is now at the middle os the list

    node *prev = NULL;
    node *curr = slow->next;
    node *tmp = NULL;
    while(curr){
        tmp = curr->next;
        curr->next = prev;
        prev = curr;

        curr = tmp;
    } //now 'prev' is the head of the reversed second half of the list

    node *p = head;
    while(prev){
        if(p->val != prev->val) //checking the values of the first half of the list with those with the reversed second half of the list
            return false;
        p = p->next;
        prev = prev->next;
    }
    return true;
}

node *create(int *arr){
    node *head = NULL;
    node **indirect = &head;
    int count = sizeof(arr)/sizeof(arr[0]); // number of nodes 
    for(int i=0;i<count;++i){
        node *newnode = malloc(sizeof(*newnode));
        if(!newnode){
            perror("Error");
            return NULL;
        }
        newnode->val = arr[i];
        newnode->next = NULL;

        *indirect = newnode;
        indirect = &newnode->next;
    }
    return head;
}
