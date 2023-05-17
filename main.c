#include "product.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <math.h>


int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("please enter the name amd path of the file you want to run\n");
        exit(1);
    }
    char *filename = ".//T5-Products-50.txt"; // argv[1];
    int num_items;

    product_t *products = load_products(filename, &num_items);
    printf("Num Items %d\n",num_items);
    pretty_print(prod1, num_items);


//    size_t a = sizeof(product_t);
//    printf("pProd struct %lu \n",a);
    return 0;

}


void clear_products(product_t *prod,int num_items) {
    for (int i = 0; i< num_items; i++) {
        clear_product(&prod[i]);
    }
}

void clear_product(product_t *prod) {
    printf("%p\n",prod);
    if (prod != NULL) {
        printf("%p\n",prod);
        printf("%p\n",prod->product_name);
        printf("%s\n",prod->product_name);
        if (prod->product_name != NULL) {
            printf("%s\n",prod->product_name);
//            free(prod->product_name);

        }
        free(prod);
//        prod = NULL;
    }

}

product_t *load_products(char* name, int* num_items) {
    FILE *in_file= NULL;
    int number_lines = 0;
    int count = 0;
    product_t *products_org = NULL;

    in_file  = fopen(name, "r"); // read only

    if (in_file == NULL) {
        printf("Error! Could not open file %s\n",name);
        fclose(in_file);
        exit(1); // must include stdlib.h
    }
    if (in_file) {
        //number_lines++;

        fscanf(in_file, "%u\n",&number_lines);

//        *num_items = number_lines;
        product_t *products= (product_t*)malloc( number_lines * sizeof(product_t) );

        if ( products == NULL ) {
            fprintf(stderr, "Error - unable to allocate required memory\n");
            return products;
        }
        products_org = products;
        while(!feof(in_file) && number_lines--) {
//            printf("NUmber of lines %d\n",number_lines+1);
            count++;
            char product_name[500];
            float discount_percentage;
            fscanf(in_file, "%lu %d %f %f %s\n", &products->product_code, &products->stock_quantity, &products->unit_price,
                   &discount_percentage, product_name);
            products->discount_percentage = (unsigned int)ceil(discount_percentage*100.0);
            products->product_name = (char*) malloc(sizeof(char)*(strlen(product_name)+1));
            strcpy(products->product_name,product_name);
//            pretty_print(products, 1);
            products++;
        }
   }
    fclose(in_file);
    *num_items = count;
    return products_org;
}

void pretty_print(product_t *products, int num_items) {

    for (int i=0; i<num_items; i++) {
        printf("%-10.10lu %-6u %-9.2f %-3d %s \n",products[i].product_code, products[i].stock_quantity, products[i].unit_price,
               products[i].discount_percentage , products[i].product_name);
    }

}