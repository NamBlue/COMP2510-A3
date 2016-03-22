#include "headers/struct.h"
#include "headers/records.h"

/*
Gets and validates a record input from stdin and stores it to record_list,
ignores invalid inputs until EOF is reached.
*/
void input_record(record_list *list) {
    char input[LINESIZE];
    char buffer[LINESIZE];
    char buffer2[LINESIZE];
    char buffer3[LINESIZE];
    int buffer4 = 0;
    int validscore = 0;/*0 for valid*/
    size_t i;
    record rec;
    
    while (fgets(input, LINESIZE, stdin)) {
        if (sscanf(input, "%s %s %s", buffer, buffer2, buffer3) == 3) {
            if (strlen(buffer) < NAMESIZE && strlen(buffer2) < NAMESIZE) {
                for (i = 0, validscore = 0; buffer3[i] != '\0'; i++) {
                    if (!isdigit((int)buffer3[i])) {
                        validscore = 1;
                    }
                }            
                if (sscanf(buffer3, "%d", &buffer4) != 1) {
                    continue;
                } else if (buffer4 < 0 || buffer4 > 100) {
                    validscore = 1;
                } else if (validscore == 0) {
                    for (i = 0; buffer[i] != '\0'; i++) {
                        buffer[i] = tolower((int)buffer[i]);
                    }
                    for (i = 0; buffer2[i] != '\0'; i++) {
                        buffer2[i] = tolower((int)buffer2[i]);
                    }
                    strcpy(rec.name.last, buffer2);
                    strcpy(rec.name.first, buffer);
                    rec.score = buffer4;
                    check_alloc(list);
                    *list->data[list->nused] = rec;
                    list->nused++;
                }
            }
        }
    }
}

/*
Checks if there is enough allocated memory for record_list and allocates
space for a record. if not enough, allocate more by BLOCK.
returns 0 for success or enough memory, any other integer for failure.
*/
int check_alloc(record_list *list) {
    record **tmp;
    
    if (list->nused == list->nalloc) {
        tmp = realloc(list->data, (list->nalloc + BLOCK) * sizeof(record *));
        if (tmp == 0) {
            fprintf(stderr, "Request for memory failed for list.data");
            return 1;
        }
        list->data = tmp;
        list->nalloc += BLOCK;
    }
    list->data[list->nused] = malloc(sizeof(record));
    if (list->data[list->nused] == 0) {
        fprintf(stderr, "Request for memory failed for list.data[%lu]", list->nused);
        return 2;
    }
    return 0;
}

/*
Prints the record_list
*/
void print_record(const record_list *list) {
    size_t i;
    for (i = 0; i < list->nused; i++) {
        printf("%s %s %d\n", list->data[i]->name.last,
            list->data[i]->name.first,
            list->data[i]->score);
    }
}

/*
Frees all dynamically allocated memory
*/
void free_memory(record_list *list) {
    size_t i;
    
    for (i = 0; i < list->nused; i++) {
        free(list->data[i]);
    }
    free(list->data);
}