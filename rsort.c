#include "headers/struct.h"
#include "headers/records.h"



/*
Main, the entry point
*/
int main (int argc, char * argv[]) {
    record_list list;
    list.data = 0;
    list.nalloc = 0;
    list.nused = 0;
    input_record(&list);
    if (argc >= 2) {
        /*check args*/
    }
    print_record(&list);
    free_memory(&list);
    return 0;
}