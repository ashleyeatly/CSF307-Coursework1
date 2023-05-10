//
// Created by Ashley Eatly on 05/05/2023.
//

#ifndef COURSEWORK1_PRODUCT_H
#define COURSEWORK1_PRODUCT_H

struct product {
//  have to evaluate how long names can be
//    char *product_name;
    char product_name[64];
//  code is range 100_000_000 to 999_999_999
//  unsigned int could be 2 or 4 bytes 0 - 65535 or 0 - 4,292.967,295
//  unsigned long would be 0 - 4,292.967,295
    unsigned long    product_code;
//  quantity is in range 0 to 500_000
    unsigned int stock_quantity;
//  price_per_unit is in range 0.01 and 10_000.00
//  we can store variable as a float but maybe use double for calculations
    float   unit_price;
    // discount can only be in theory 0 - 100%
    // can it be a float
    float discount_percentage;
};

typedef struct product product_t;

product_t load_products(char *filename);
product_t *task_2_load_products(char* name);
product_t *task_5_load_products(char* name,int* num_items);
void pretty_print(product_t *products, int num_items);
#endif //COURSEWORK1_PRODUCT_H
