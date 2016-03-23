#include "headers/struct.h"
#include "headers/records.h"
#include "headers/cmp.h"

/*
Method protoypes declared here
*/
void check_args(char *argv[], record_list *list);

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
        check_args(argv, &list);
    }
    print_record(&list);
    free_memory(&list);
    return 0;
}

/*
Checks arguments to determine which sort to use
*/
void check_args(char *argv[], record_list *list) {
    
    if (argv[1] != '\0' && argv[2] != '\0') {
        if (strcmp(argv[1], "+n") == 0 && strcmp(argv[2], "+s") == 0) {
            qsort(list->data, list->nused, sizeof(list->data[0]), sna_ssa);
        } else if (strcmp(argv[1], "+n") == 0 && strcmp(argv[2], "-s") == 0) {
            qsort(list->data, list->nused, sizeof(list->data[0]), sna_ssd);
        } else if (strcmp(argv[1], "-n") == 0 && strcmp(argv[2], "+s") == 0) {
            qsort(list->data, list->nused, sizeof(list->data[0]), snd_ssa);
        } else if (strcmp(argv[1], "-n") == 0 && strcmp(argv[2], "-s") == 0) {
            qsort(list->data, list->nused, sizeof(list->data[0]), snd_ssd);
        } else if (strcmp(argv[1], "+s") == 0 && strcmp(argv[2], "+n") == 0) {
            qsort(list->data, list->nused, sizeof(list->data[0]), ssa_sna);
        } else if (strcmp(argv[1], "+s") == 0 && strcmp(argv[2], "-n") == 0) {
            qsort(list->data, list->nused, sizeof(list->data[0]), ssa_snd);
        } else if (strcmp(argv[1], "-s") == 0 && strcmp(argv[2], "+n") == 0) {
            qsort(list->data, list->nused, sizeof(list->data[0]), ssd_sna);
        } else if (strcmp(argv[1], "-s") == 0 && strcmp(argv[2], "-n") == 0) {
            qsort(list->data, list->nused, sizeof(list->data[0]), ssd_snd);
        }
    } else if (argv[1] != '\0') {
        if (strcmp(argv[1], "+n") == 0) {
            qsort(list->data, list->nused, sizeof(list->data[0]), sname_asc);
        } else if (strcmp(argv[1], "-n") == 0) {
            qsort(list->data, list->nused, sizeof(list->data[0]), sname_desc);
        } else if (strcmp(argv[1], "+s") == 0) {
            qsort(list->data, list->nused, sizeof(list->data[0]), sscore_asc);
        } else if (strcmp(argv[1], "-s") == 0) {
            qsort(list->data, list->nused, sizeof(list->data[0]), sscore_desc);
        }
    }
}