//
// Created by Ashley Eatly on 14/05/2023.
//
#include <stdio.h>

#include <string.h>
//#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "test2.h"


int main(int argc, char* argv[]) {
    int num_lines = 0;
//    We actually know there are 4 lines here
    simple_t *simple = test(".//temp_file2.txt", &num_lines);
    simple_t *simple_keep = NULL;
    simple_keep = simple;

    // now after reading the file
    // we get the pointer to where the array is in memory as a return
    // and we also check num_lines which should be 4
    printf("array starts at %p\n", simple);
    printf("number items in array %d\n", num_lines);

    for (int i=0; i<4; i++) {
        printf("printing array at %p\n", simple);
        printf("%d %d %d %s\n",simple->first, simple->second, simple->third, simple->rubbish);
        // move to next line
        printf("moving on simple++\n");
        simple++;
        printf("array now at %p\n", simple);
    }

    simple = simple_keep;
    for (int i=0; i<4; i++) {
        printf("printing array at %p\n", &simple_keep[i]);
            printf("%d %d %d %s\n",simple_keep[i].first, simple_keep[i].second, simple_keep[i].third, simple_keep[i].rubbish);
        // move to next line
        printf("moving on simple++\n");
//        simple++;
//        printf("array now at %p\n", simple);
    }

    size_t a = sizeof(simple_t);
    printf("simple struct %lu \n",a);
    return 0;

}

simple_t *test(char* name, int* num_items) {
    FILE *in_file= NULL;
    int number_lines = 0;
    int count = 0;

    // Have this to use to point to start of the maalloc ed array in memory
    // You have to return this to tell the calling code where the array exists etc.
    simple_t *simple_keep = NULL;


    in_file  = fopen(name, "r"); // read only

    if (in_file == NULL) {
        printf("Error! Could not open file %s\n",name);
        fclose(in_file);
        exit(1); // must include stdlib.h
    }
    if (in_file) {
        int number_lines = 4;

//        fscanf(in_file, "%u\n",&number_lines);
        // for this one we know there is 4 just like in first coursewoork its 30

        *num_items = number_lines;

        // so here we are allocating 4 lines in the array in memory

        simple_t *simple_working= (simple_t*)malloc( number_lines * sizeof(simple_t) );
        // now we have a char string of variable length but hey lets allocate it when we know its size
        if ( simple_working == NULL ) {
            fprintf(stderr, "Error - unable to allocate required memory\n");
            return simple_working;
        }
        // This makes sure simple_keep is pointing to startr of array in memory for later use
        simple_keep = simple_working;
        printf("array start in memory %p\n",simple_keep);
        printf("array working in memory %p\n",simple_working);

        // while(!feof(in_file)) {
        // simple_t prod;
        while(number_lines--) {
            printf("Number of lines %d\n",number_lines+1);
            printf("filling array working in memory %p\n",simple_working);

            // we copuld malloc or just have a temporary string
            char temp_str[500];
            // read in one line from file and populate the array where simple_working is pointing to
            fscanf(in_file, "%d %d %d %s\n", &simple_working->first, &simple_working->second, &simple_working->third, temp_str);
            printf(" The string is %lu chars \n",strlen(temp_str));
            // allocate the space somewhere
            // and get the pointer to it
             simple_working->rubbish = (char*) malloc(sizeof(char)*strlen(temp_str));
             printf("the string will go in heap at %p\n",simple_working->rubbish);
             // then copy the data there
            strcpy(simple_working->rubbish,temp_str);
            printf("printing array working in memory %p\n",simple_working);
            printf("%d %d %d %s\n",simple_working->first, simple_working->second, simple_working->third, simple_working->rubbish);
//            printf(" The string is %lu chars \n",strlen(product_name));
//            products->product_name = (char*) malloc(sizeof(char)*strlen(product_name));
//            strcpy(products->product_name,product_name);
//            pretty_print(products, 1);
//            *products = prod;
            // =get ready to fill second line
            simple_working++;
            count++;
            printf("array start in memory %p\n",simple_keep);
            printf("array working in memory moved  %p\n",simple_working);
            printf("NUmber of lines %d\n",number_lines);
        }
        printf("NUmber of lines %d\n",number_lines);
        // read from file/keyboard. remember the ampersands!
    }
    fclose(in_file);
    *num_items=count;
    printf("array start in memory %p\n",simple_keep);
    return simple_keep;
}