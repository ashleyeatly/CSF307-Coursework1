//
// Created by Ashley Eatly on 05/05/2023.
//

#ifndef COURSEWORK1_PRODUCT_H
#define COURSEWORK1_PRODUCT_H

typedef struct product {
//  have to evaluate how long names can be
//    char *product_name;
//char product_name[64];
    char *product_name;
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
    // can it be a float - no replace unchanged car 0 - 255
    unsigned int discount_percentage;
} product_t;

//typedef struct product product_t;

product_t *load_products(char *filename, int *num_items);
float calculate_score(product_t *prod1, unsigned long *product_code);
void pretty_print(product_t *products, int num_items);
void clear_products(product_t *prod, int num_items);
void clear_product(product_t *prod);
#endif //COURSEWORK1_PRODUCT_H
