#include <malloc.h>
#include "mutilist.h"

int main (void) {
    mutilist_t* root = (mutilist_t*)malloc(sizeof(mutilist_t));
    mutilist_t *son1, *son2, *son3, *son4;
    // init root
    root->val = 0;
    root->sibling.post = 0;
    root->sibling.prev = 0;
    root->children.post = 0;
    root->children.prev = 0;
    root->parent = 0;
                              
    mutilist_addson (root, 1);
    mutilist_addson (root, 2);
    mutilist_addson (root, 3);
    mutilist_addson (root, 4);

    son1 = mutilist_getson (root);
    mutilist_addson (son1, 5);
    mutilist_addson (son1, 6);
    mutilist_addson (son1, 7);
    mutilist_addson (son1, 8);
                                                                
    son2 = mutilist_getbrother (son1);
    mutilist_addson (son2, 6);
    mutilist_addson (son2, 9);
    mutilist_addson (son2, 1);
    mutilist_addson (son2, 7);

    son3 = mutilist_getbrother (son2);
    mutilist_addson (son3, 6);
    mutilist_addson (son3, 3);
    mutilist_addson (son3, 3);
    mutilist_addson (son3, 3);

    son4 = mutilist_getbrother (son3);
    mutilist_addson (son4, 4);
    mutilist_addson (son4, 5);
    mutilist_addson (son4, 7);
    mutilist_addson (son4, 3);

    display (root, 0);
    return 0;
}
