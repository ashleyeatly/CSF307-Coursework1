//
// Created by Ashley Eatly on 05/05/2023.
//

#include "product.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <math.h>

//int main() {
//    product_t *prod1 = task_2_load_products(".//T2-Products.txt");
//    init
//    return 0;
//}

void pretty_print(product_t *products, int num_items) {
    for (int i=0; i<num_items; i++) {
        printf("%-10lu %-6u %-9.2f %-3d %s \n",products[i].product_code, products[i].stock_quantity, products[i].unit_price,
               products[i].discount_percentage , products[i].product_name);
    }
}


product_t *task_2_load_products(char* name) {
    FILE *in_file = NULL;

    int number_lines = 30;

    product_t *products = (product_t* )malloc( number_lines * sizeof(product_t) );


    if ( products == NULL ) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
        return products;
    }
    product_t *products_org = products;

    in_file = fopen(name, "r"); // read only

    if (in_file == NULL) {
        printf("Error! Could not open file %s\n", name);
        fclose(in_file);
        exit(1); // must include stdlib.h
    }


    if (in_file) {
        while (!feof(in_file)) {
            char product_name[500];
            float percentage;
            fscanf(in_file, "%lu %d %f %f %s\n", &products->product_code, &products->stock_quantity, &products->unit_price,
                   &percentage, product_name);
            products->discount_percentage = (unsigned char)(ceil(percentage*100));
            number_lines++;
            products->product_name = (char*) malloc(sizeof(char)*strlen(product_name));
            strcpy(products->product_name,product_name);
            pretty_print(products, 1);
            products++;
//            printf("NUmber of lines %d\n", number_lines);
        }
//        printf("NUmber of lines %d\n", number_lines);
        // read from file/keyboard. remember the ampersands!
    }
    fclose(in_file);
    return products_org;
}