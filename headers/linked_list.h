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

#endif
