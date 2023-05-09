#include <stdio.h>

#include "product.h"
#include <string.h>
//#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


int main(int argc, char* argv[]) {

//    if (argc > 1) {
//        load_products(argv[1]);
//    }
    load_products("..//T5-Products-10.txt");
    product_t prod1, *pProd = &prod1;
    product_t *pProd1;

    prod1.code = 100000;
    prod1.discount = 1.0;

    char name[20] = "just a test";
    strcpy(prod1.name,name);

    prod1.price_per_unit = 10.01;
    prod1.quantity = 1000;

    printf("prod1 name %s\n",prod1.name);
    printf("prod1 code %lu\n",prod1.code);
    printf("prod1 price_per_unit %0.2f\n",prod1.price_per_unit);
    printf("prod1 quantity %u\n",prod1.quantity);

    printf("*pProd  name %s \n",(*pProd).name);
    printf("*pProd  code %lu \n",(*pProd).code);
    printf("*pProd  price_per_unit %0.2f \n",(*pProd).price_per_unit);
    printf("*pProd quantity %u \n",(*pProd).quantity);

    pProd1 = pProd;
    printf("*pProd1  name %s \n",(*pProd1).name);
    printf("*pProd1  code %lu \n",(*pProd1).code);
    printf("*pProd1  price_per_unit %0.2f \n",(*pProd1).price_per_unit);
    printf("*pProd1 quantity %u \n",(*pProd1).quantity);

    printf("pProd  name %s \n",pProd->name);
    printf("pProd  code %lu \n",pProd->code);
    printf("pProd  price_per_unit %0.2f \n",pProd->price_per_unit);
    printf("pProd quantity %u \n",pProd->quantity);

    return 0;

}

product_t load_products(char* name) {
    FILE *in_file= NULL;

    char buffer[100];
    int year;
    char space[]="                                           ";
    char title[]="                                           ";
    int number_lines = 0;

    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    in_file  = fopen(name, "r"); // read only

    if (in_file == NULL) {
        printf("Error! Could not open file %s\n",name);
        fclose(in_file);
        exit(1); // must include stdlib.h
    }

    product_t prod;
    if (in_file) {
        while(!feof(in_file)) {
            number_lines++;
            fscanf(in_file, "%lu %d %f %f %s\n",&prod.code,&prod.quantity,&prod.price_per_unit,&prod.discount,prod.name);
            printf("%lu\n",(&prod)->code);
            printf("%u\n",(&prod)->quantity);
            printf("%f\n",(&prod)->price_per_unit);
            printf("%f\n",(&prod)->discount);
            printf("%s\n",(&prod)->name);
            printf("NUmber of lines %d\n",number_lines);
        }
        printf("NUmber of lines %d\n",number_lines);
        // read from file/keyboard. remember the ampersands!
    }
    fclose(in_file);

}