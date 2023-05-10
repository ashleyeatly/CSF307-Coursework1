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
//        printf("%lu\n",prod1->product_code);
//        printf("%u\n",prod1->stock_quantity);
//        printf("%f\n",prod1->unit_price);
//        printf("%f\n",prod1->discount_percentage);
//        printf("%s\n",prod1->product_name);
        prod1++;
    }

    int num_items = 0;
    product_t *prod2 = task_5_load_products("..//T5-Products-50.txt",&num_items);
    product_t *prod = prod2;
    pretty_print(prod, 30);
//    for (int i=0; i<num_items; i++) {
//        printf("i is %d\n",i);
//        printf("%lu %u %f %f %s \n",prod2->product_code, prod2->stock_quantity, prod2->unit_price,
//               prod2->discount_percentage, prod2->product_name);
//        prod2++;
//    }

    size_t a = sizeof(product_t);
    printf("pProd struct %lu \n",a);
    return 0;

}

product_t *task_5_load_products(char* name, int* num_items) {
    FILE *in_file= NULL;
    int number_lines = 0;

    in_file  = fopen(name, "r"); // read only

    product_t *products = malloc( 30 * sizeof(product_t) );

    if ( products == NULL ) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
        return products;
    }
    product_t *products_org = products;

    if (in_file == NULL) {
        printf("Error! Could not open file %s\n",name);
        fclose(in_file);
        exit(1); // must include stdlib.h
    }
    if (in_file) {
        //number_lines++;
        product_t prod;
        fscanf(in_file, "%u\n",&number_lines);
        *num_items = number_lines;
        // while(!feof(in_file)) {
        while(number_lines--) {
            printf("NUmber of lines %d\n",number_lines+1);
            fscanf(in_file, "%lu %d %f %f %s\n", &prod.product_code, &prod.stock_quantity, &prod.unit_price,
                   &prod.discount_percentage, prod.product_name);
            printf("%lu %u %f %f %s \n",prod.product_code, prod.stock_quantity, prod.unit_price,
                   prod.discount_percentage, prod.product_name);
            *products = prod;
            products++;
            printf("NUmber of lines %d\n",number_lines);
        }
        printf("NUmber of lines %d\n",number_lines);
        // read from file/keyboard. remember the ampersands!
    }
    fclose(in_file);
    return products_org;
}

product_t *task_2_load_products(char* name) {
    FILE *in_file = NULL;

//    char buffer[100];
//    int year;
//    char space[] = "                                           ";
//    char title[] = "                                           ";
    int number_lines = 0;

    product_t *products = malloc( 30 * sizeof(product_t) );


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
            product_t prod;
            fscanf(in_file, "%lu %d %f %f %s\n", &prod.product_code, &prod.stock_quantity, &prod.unit_price,
                   &prod.discount_percentage, prod.product_name);
            printf("%lu %u %f %f %s \n",prod.product_code, prod.stock_quantity, prod.unit_price,
                   prod.discount_percentage, prod.product_name);
            number_lines++;
            *products = prod;
            products++;
            printf("NUmber of lines %d\n", number_lines);
        }
        printf("NUmber of lines %d\n", number_lines);
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
        printf("product_code %10lu %6u %9.2f %d %s \n",products->product_code, products->stock_quantity, products->unit_price,
               percentage , products->product_name);
        *products++;
    }

}