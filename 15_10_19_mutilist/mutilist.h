#ifndef _MUTILIST_H_
#define _MUTILIST_H_

typedef struct _list {
    struct _list *prev;
    struct _list *post;
}list_t;

typedef struct _mutilist {
    struct _mutilist *parent;
    list_t children;
    list_t sibling;
    int val;
}mutilist_t;

void mutilist_addson (mutilist_t *node, int data);
mutilist_t* mutilist_getson (mutilist_t *node);
mutilist_t* mutilist_getparent (mutilist_t *node);
mutilist_t* mutilist_getbrother (mutilist_t *node);

#define GET_PTR(_t,_m,_p) (_t*)((unsigned long)_p-((unsigned long)(&((_t*)0)->_m)))

#endif

