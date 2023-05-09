//
// Created by Ashley Eatly on 05/05/2023.
//

#ifndef COURSEWORK1_PRODUCT_H
#define COURSEWORK1_PRODUCT_H

struct product {
//  have to evaluate how long names can be
    char name[64];
//  code is range 100_000_000 to 999_999_999
//  unsigned int could be 2 or 4 bytes 0 - 65535 or 0 - 4,292.967,295
//  unsigned long would be 0 - 4,292.967,295
    unsigned long    code;
//  quantity is in range 0 to 500_000
    unsigned int quantity;
//  price_per_unit is in range 0.01 and 10_000.00
//  we can store variable as a float but maybe use double for calculations
    float   price_per_unit;
    // discount can only be in theory 0 - 100%
    // can it be a float
    float discount;
};

typedef struct product product_t;

product_t load_products(char *filename);

#endif //COURSEWORK1_PRODUCT_H
