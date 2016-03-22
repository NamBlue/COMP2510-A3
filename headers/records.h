#ifndef records_h
#define records_h
#define LINESIZE 256
#define BLOCK 2
void input_record(record_list *list);
void print_record(const record_list *list);
int check_alloc(record_list *list);
void free_memory(record_list *list);
#endif