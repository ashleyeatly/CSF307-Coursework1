//
// Created by Ashley Eatly on 15/05/2023.
//
#include "trie.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <math.h>

/* Allocate a new empty trie.  */
trie_t *trie_new(void) {
    trie_t *pNode = NULL;

    pNode = (trie_t *)malloc(sizeof (trie_t));

    if (pNode) {
        int i;

        for (int i=0; i < TRIE_CHILDREN; i++) {
            pNode->children[i] = NULL;
        }
    }
//    trie_t *trie = (trie_t *)malloc(sizeof (trie_t));

//    trie->children_size = TRIE_CHILDREN;
//    trie->children_count = 0;
//    trie->children = (trie_t *) malloc (TRIE_CHILDREN * sizeof (trie_t));
//    memset(trie->children, 0, TRIE_CHILDREN * sizeof (trie_t));
    return pNode;
}

void free_trie(trie_t *trie) {
    for (int i=0; i< TRIE_CHILDREN; i++) {
        if (trie->children[i]!= NULL) {
            free_trie(trie->children[i]);
        } else {
            continue;
        }
    }
    free(trie);
}

void insert(trie_t *root,product_t *product) {
    trie_t *pCrawl = root;

    char buffer[100];
    sprintf(buffer,"%lu\n",product->product_code);
//    printf("buffer is %s\n", buffer);
//    printf("buffer is %lu\n", strlen(buffer));
//    for (int i=0; i< strlen(buffer)+1; i++) {
//        puts(&buffer[i]);
//    }
//    puts("end");

    for (int i = 0; i< strlen(buffer)-1; i++) {
//        printf("insert strlen buffer %lu\n",strlen(buffer));
//        printf("insert buffer %s\n",buffer);
//        printf("insert product code %lu\n",product->product_code);
        int index = buffer[i] - '0';
//        printf("insert index %d\n",index);
//        printf(" pCrawl->children[index] %p\n",pCrawl->children[index]);

        trie_t *pNext = pCrawl->children[index];
        if (pNext== NULL) {
            pNext = trie_new();
            pCrawl->children[index] = pNext;
        }
//        printf("insert pNext %p\n",pNext);

        pCrawl = pNext;
    }
//    printf("insert pCrawl->product %p\n",pCrawl->product);

    pCrawl ->product = product;
//    printf("insert pCrawl->product %p\n",pCrawl->product);

}

product_t *get_product(trie_t *root, unsigned long product_code){
    trie_t *pCrawl = root;
    trie_t *pNext = NULL;

    char buffer[100];
    sprintf(buffer,"%lu\n",product_code);
//    printf("buffer is %s\n", buffer);
//    printf("buffer is %lu\n", strlen(buffer));
//    for (int i=0; i< strlen(buffer)+1; i++) {
//        puts(&buffer[i]);
//    }
//    puts("end");

    for (int i = 0; i< strlen(buffer)-1; i++) {
//        printf("get product code %lu\n",product_code);
        int index = buffer[i] - '0';
//        printf("get index %d\n",index);
//        printf(" get  pCrawl->children[index] %p\n",pCrawl->children[index]);

        trie_t *pNext = pCrawl->children[index];
        if (pNext== NULL) {
            return NULL;
//            pNext = trie_new();
//            pCrawl->children[index] = pNext;
        }
//        printf("get pNext %p\n",pNext);

        pCrawl = pNext;
    }
//    printf("get  pCrawl->product %p\n",pCrawl->product);

//    pCrawl ->product = product;
//    printf(" pCrawl->product %p\n",pCrawl->product);
    return pCrawl->product;
}