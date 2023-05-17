//
// Created by Ashley Eatly on 15/05/2023.
//
#ifndef CLIONPROJECTS_PRODUCT_H
#include "product.h"
#endif

#ifndef CLIONPROJECTS_TRIE_H
#define CLIONPROJECTS_TRIE_H
/**
 * The trie has a pointer to a product (it can be null)
 * The trie has children - which in this implementation is actually 10
 * could have been defined as trie_t children[10] or trie_t *children and
 * the 10 are allocated when a trie is created
 * 0,1,2,3,4,5,6,7,8,9
 * I know many have flags to state its a tree node but is this necessary
 */
#define TRIE_CHILDREN 10
#include <stdbool.h>

//typedef struct trie_node trie_t;

typedef struct  trie_node {
    struct trie_node *children[TRIE_CHILDREN];
    product_t  *product;
}trie_t;

trie_t *trie_new(void);
void init_trie(trie_t *trie);
trie_t *allocate_trie(void);
void free_trie(trie_t *trie);
void deallocate_trie(trie_t *trie);
void add_product_to_trie(trie_t *root, product_t *product);
trie_t *get_trie_node(trie_t *trie, const product_t *product);
bool product_in_trie(trie_t *trie, const product_t *product);
void insert(trie_t *root, product_t *product);
product_t *get_product(trie_t *root,unsigned long product_code);

// the product_code is max 10 characters 0 1 2 3 4 5 6 7 8 9
//#define TRIE_CHILDREN 10

#endif //CLIONPROJECTS_TRIE_H
