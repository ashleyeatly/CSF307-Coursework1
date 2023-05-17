//
// Created by Ashley Eatly on 15/05/2023.
//

#include "coursework.h"
#include "product.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <math.h>
#include "trie.h"

int main() {
    trie_t *root = trie_new();

    product_t *prod1 = task_2_load_products(".//T2-Products.txt");
    if ((root->product) == NULL) {
        printf("trie exists and has no children\n");
    } else {
        printf("trie exists and has children\n");
//     want to find 2927164024
    }
    for (int i=0; i<TRIE_CHILDREN; i++) {
        if (root->children[i] == NULL) {
            printf("child %d is NULL\n",i);
        } else {
            printf("child %d is NOT NULL\n",i);
        }
    }
    return 0;
}