#include <stdio.h>

#include "product.h"
#include <string.h>
//#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <math.h>


int main(int argc, char* argv[]) {

//    if (argc > 1) {
//        load_products(argv[1]);
//    }
    product_t *prod1 = task_2_load_products("..//T2-Products.txt");
    for (int i=0; i<30; i++) {
//        printf("%lu\n", *prod1);
        printf("prod1 i is %d\n",i);
        printf("%lu %u %f %f %s \n",prod1->product_code, prod1->stock_quantity, prod1->unit_price,
               prod1->discount_percentage, prod1->product_name);

        prod1++;
    }

    int num_items = 0;
    product_t *prod2 = task_5_load_products("..//T5-Products-50.txt",&num_items);
    product_t *prod = prod2;
    pretty_print(prod, 30);

    size_t a = sizeof(product_t);
    printf("pProd struct %lu \n",a);
    return 0;

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
            product_t prod = {"TRIAL",1000,200,1.20,0.25};
            char product_name[500];
            fscanf(in_file, "%lu %d %f %f %s\n", &products->product_code, &products->stock_quantity, &products->unit_price,
                   &products->discount_percentage, product_name);
//            printf("%lu %u %f %f %s \n",product_code, stock_quantity, unit_price,
//                   discount_percentage, product_name);
            number_lines++;
//          As we have used malloc this is created in the Heap
//          Local variables are placed on stack and they are destroyed on exit
//          No need to manage the freeing up of the space
            products->product_name = (char*) malloc(sizeof(char)*strlen(product_name));
            strcpy(products->product_name,product_name);
//
            pretty_print(products, 1);
            products++;
            printf("NUmber of lines %d\n", number_lines);
        }
        printf("NUmber of lines %d\n", number_lines);
        // read from file/keyboard. remember the ampersands!
    }
    fclose(in_file);
    return products_org;
}

product_t *task_5_load_products(char* name, int* num_items) {
    FILE *in_file= NULL;
    int number_lines = 0;
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

        *num_items = number_lines;
        product_t *products= (product_t*)malloc( number_lines * sizeof(product_t) );

        if ( products == NULL ) {
            fprintf(stderr, "Error - unable to allocate required memory\n");
            return products;
        }
        products_org = products;
        // while(!feof(in_file)) {
        product_t prod;
        while(number_lines--) {
            printf("NUmber of lines %d\n",number_lines+1);
            char product_name[500];
            fscanf(in_file, "%lu %d %f %f %s\n", &products->product_code, &products->stock_quantity, &products->unit_price,
                   &products->discount_percentage, product_name);
//            printf("%lu %u %f %f %s \n",product_code, stock_quantity, unit_price,
//                   discount_percentage, product_name);
            printf(" The string is %lu chars \n",strlen(product_name));
            products->product_name = (char*) malloc(sizeof(char)*strlen(product_name));
            strcpy(products->product_name,product_name);
            pretty_print(products, 1);
//            *products = prod;
            products++;
            printf("NUmber of lines %d\n",number_lines);
        }
        printf("NUmber of lines %d\n",number_lines);
        // read from file/keyboard. remember the ampersands!
    }
    fclose(in_file);
    return products_org;
}

void pretty_print(product_t *products, int num_items) {
    int percentage;
    for (int i=0; i<num_items; i++) {
        printf("i is %d\n",i);
        percentage = ceil((products->discount_percentage)*100.0);
        printf("product_code %-10lu %-6u %-9.2f %-3d %s \n",products->product_code, products->stock_quantity, products->unit_price,
               percentage , products->product_name);
        *products++;
    }

}