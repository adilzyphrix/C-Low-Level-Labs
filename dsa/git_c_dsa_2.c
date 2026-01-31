#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define COUNT 5 //number of nodes

struct node{
    int val;
    struct node *next;
};

int main()
{
    struct node *ll = calloc(COUNT,sizeof(struct node)); //dynamically allocating the linked list
    if(!ll){
        perror("Error");
        exit(1);
    } //error handling

    for(int i=0;i<COUNT;i++)
        ll[i].val = i+1; //initialisation of value
    
    for(int i=0;i<COUNT-1;i++)
        ll[i].next = &ll[i+1]; //linking the nodes

    struct node *p = &ll[0]; //head of the linked list
    struct node *p1 = p->next; //variable pointer

    for(int i=0;i<COUNT;i++)
        printf("%d %p\n",ll[i].val,ll[i].next); //print linked list
    
    free(ll);
    return 0;
}
