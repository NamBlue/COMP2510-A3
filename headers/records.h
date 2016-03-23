#ifndef records_h
#define records_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAMESIZE 20
#define LINESIZE 256
#define BLOCK 2
typedef struct name {
    /*last name*/
    char last[NAMESIZE];
    /*first name*/
    char first[NAMESIZE];
} name;

typedef struct record {
    name name;
    /*score between 0 - 100 inclusive*/
    int score;
} record;

typedef struct record_list {
    record **data; /* points to dynamic array of pointers */
    size_t nalloc; /* number of pointers allocated */
    size_t nused; /* number of pointers used */
} record_list;

void input_record(record_list *list);
void print_record(const record_list *list);
int check_alloc(record_list *list);
void free_memory(record_list *list);
#endif