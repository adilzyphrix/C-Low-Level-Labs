#ifndef LIST_H
#define LIST_H

typedef struct node{
    int val;
    struct node *next;
}node;

node *create_ll(int);
void insert_ll(node **,int);
node *delete_ll(node *,int);
void free_ll(node **);
void traverse_ll(const node *);

extern int arr[]; //it is necessary to declare this array as extern in the header file, before using it any other .c file
extern int k; //required for some LeetCode problems

#endif
