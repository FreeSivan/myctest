#include "mutilist.h"
#include <stdio.h>
#include <malloc.h>

void mutilist_addson (mutilist_t *node, int data) {
    mutilist_t *son = (mutilist_t*)malloc(sizeof(mutilist_t));
    son->val = data;
    son->parent = node;
    son->sibling.post = node->children.post;
    if (node->children.post) {
        node->children.post->prev = &son->sibling;
    }
    node->children.post = &son->sibling;
    son->sibling.prev = &node->children;
    
    son->children.prev = 0;
    son->children.post = 0;
}

mutilist_t* mutilist_getson (mutilist_t *node) {
    if (!node) {
        return 0;
    }
    return GET_PTR(mutilist_t,sibling,node->children.post);
}

mutilist_t* mutilist_getparent (mutilist_t *node) {
    if (!node) {
        return 0;
    }
    return node->parent;
}

mutilist_t* mutilist_getbrother (mutilist_t *node) {
    if (!node) {
        return 0;
    }
    return GET_PTR(mutilist_t,sibling,node->sibling.post);
}

void display (mutilist_t *node, int index) {
    int i;
    if (!node) {
        return;
    }
    for (i = 0; i < index; ++i) {
        printf ("   ");
    }
    printf ("%d\n",node->val);
    if (node->children.post) {
        display (GET_PTR(mutilist_t,sibling,node->children.post), index+1);
    }
    if (node->sibling.post) {
        display (GET_PTR(mutilist_t,sibling,node->sibling.post), index);
    }
}

