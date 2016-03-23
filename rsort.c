#include "headers/records.h"
#include "headers/cmp.h"

/*
Method protoypes declared here
*/
void check_args(char *argv[], record_list *list);
void print_error(void);
/*
Main, the entry point
Initializes record list, checks argc for correct 
number of invocations, and calls all other functions.
*/
int main (int argc, char * argv[]) {
    record_list list;
    list.data = 0;
    list.nalloc = 0;
    list.nused = 0;
    if (argc > 3) {
        print_error();
    } else if (argc >= 2) {
        check_args(argv, &list);
    } else {
        input_record(&list);
    }
    print_record(&list);
    free_memory(&list);
    return 0;
}

/*
Checks arguments, if valid, calls input_record function
then determines which sort to use
*/
void check_args(char *argv[], record_list *list) {
    
    if (argv[1] != '\0' && argv[2] != '\0') {
        if (strcmp(argv[1], "+n") == 0 && strcmp(argv[2], "+s") == 0) {
            input_record(list);
            qsort(list->data, list->nused, sizeof(list->data[0]), sna_ssa);
        } else if (strcmp(argv[1], "+n") == 0 && strcmp(argv[2], "-s") == 0) {
            input_record(list);
            qsort(list->data, list->nused, sizeof(list->data[0]), sna_ssd);
        } else if (strcmp(argv[1], "-n") == 0 && strcmp(argv[2], "+s") == 0) {
            input_record(list);
            qsort(list->data, list->nused, sizeof(list->data[0]), snd_ssa);
        } else if (strcmp(argv[1], "-n") == 0 && strcmp(argv[2], "-s") == 0) {
            input_record(list);
            qsort(list->data, list->nused, sizeof(list->data[0]), snd_ssd);
        } else if (strcmp(argv[1], "+s") == 0 && strcmp(argv[2], "+n") == 0) {
            input_record(list);
            qsort(list->data, list->nused, sizeof(list->data[0]), ssa_sna);
        } else if (strcmp(argv[1], "+s") == 0 && strcmp(argv[2], "-n") == 0) {
            input_record(list);
            qsort(list->data, list->nused, sizeof(list->data[0]), ssa_snd);
        } else if (strcmp(argv[1], "-s") == 0 && strcmp(argv[2], "+n") == 0) {
            input_record(list);
            qsort(list->data, list->nused, sizeof(list->data[0]), ssd_sna);
        } else if (strcmp(argv[1], "-s") == 0 && strcmp(argv[2], "-n") == 0) {
            input_record(list);
            qsort(list->data, list->nused, sizeof(list->data[0]), ssd_snd);
        } else {
            print_error();
        }
    } else if (argv[1] != '\0') {
        if (strcmp(argv[1], "+n") == 0) {
            input_record(list);
            qsort(list->data, list->nused, sizeof(list->data[0]), sname_asc);
        } else if (strcmp(argv[1], "-n") == 0) {
            input_record(list);
            qsort(list->data, list->nused, sizeof(list->data[0]), sname_desc);
        } else if (strcmp(argv[1], "+s") == 0) {
            input_record(list);
            qsort(list->data, list->nused, sizeof(list->data[0]), sscore_asc);
        } else if (strcmp(argv[1], "-s") == 0) {
            input_record(list);
            qsort(list->data, list->nused, sizeof(list->data[0]), sscore_desc);
        } else {
            print_error();
        }
    }
}

/*
If an invocation is invalid, a usage message is printed to standard error
then exits program.
*/
void print_error(void) {
    fprintf(stderr, "\n%s\n\n%s\n%s\n%s\n%s\n%s\n\n%s\n%s\n%s\n%s\n\n%s\n%s\n\n%s\n%s\n" 
    , "Error, invalid invocation, Correct usage:"
    ,"e.g valid arguments:"
    ,"rsort +n -s"
    ,"rsort -n +s"
    ,"rsort +n +s"
    ,"rsort +s -n"

    ,"e.g invalid arguments:"
    ,"rsort +s -s"
    ,"rsort +n -n"
    ,"rsort +n -s -n"

    ,"rsort -s +n sorts in descending order of scores; if two or more records have"
    ,"the same score, they are then sorted in ascending order of their names."

    ,"rsort +n -s sorts in ascending order of names; if two or more records have the"
    ,"same name, they are then sorted in descending order of their scores.");
    exit(1);
}