#include "headers/cmp.h"
#include "headers/records.h"

/*
Sorts by name in ascending order
*/
int sname_asc(const void *p, const void *q) {
    record * const *pp = p;
    record * const *qq = q;
    int x;
    x = strcmp((*pp)->name.last, (*qq)->name.last);
    if (x != 0) {
        return x;
    } else {
        return strcmp((*pp)->name.first, (*qq)->name.first);
    }
}

/*
Sorts by name in descending order
*/
int sname_desc(const void *p, const void *q) {
    record * const *pp = p;
    record * const *qq = q;
    int x;
    x = strcmp((*qq)->name.last, (*pp)->name.last);
    if (x != 0) {
        return x;
    } else {
        return strcmp((*qq)->name.first, (*pp)->name.first);
    }
}

/*
Sorts by score in ascending order
*/
int sscore_asc(const void *p, const void *q) {
    record * const *pp = p;
    record * const *qq = q;
    return (*pp)->score - (*qq)->score;
}

/*
Sorts by score in descending order
*/
int sscore_desc(const void *p, const void *q) {
    record * const *pp = p;
    record * const *qq = q;
    return (*qq)->score - (*pp)->score;
}

/*
Sorts by name in ascending order, 
then by score in ascending order
*/
int sna_ssa(const void *p, const void *q) {
    record * const *pp = p;
    record * const *qq = q;
    int x;
    x = strcmp((*pp)->name.last, (*qq)->name.last);
    if (x != 0) {
        return x;
    } else if ((x = strcmp((*pp)->name.first, (*qq)->name.first)) != 0){
        return x;
    } else {
        return (*pp)->score - (*qq)->score;
    }
}

/*
Sorts by name in ascending order, 
then by score in descending order
*/
int sna_ssd(const void *p, const void *q) {
    record * const *pp = p;
    record * const *qq = q;
    int x;
    x = strcmp((*pp)->name.last, (*qq)->name.last);
    if (x != 0) {
        return x;
    } else if ((x = strcmp((*pp)->name.first, (*qq)->name.first)) != 0){
        return x;
    } else {
        return (*qq)->score - (*pp)->score;
    }
}

/*
Sorts by name in descending order, 
then by score in ascending order
*/
int snd_ssa(const void *p, const void *q) {
    record * const *pp = p;
    record * const *qq = q;
    int x;
    x = strcmp((*qq)->name.last, (*pp)->name.last);
    if (x != 0) {
        return x;
    } else if ((x = strcmp((*qq)->name.first, (*pp)->name.first)) != 0){
        return x;
    } else {
        return (*pp)->score - (*qq)->score;
    }
}

/*
Sorts by name in descending order, 
then by score in descending order
*/
int snd_ssd(const void *p, const void *q) {
    record * const *pp = p;
    record * const *qq = q;
    int x;
    x = strcmp((*qq)->name.last, (*pp)->name.last);
    if (x != 0) {
        return x;
    } else if ((x = strcmp((*qq)->name.first, (*pp)->name.first)) != 0){
        return x;
    } else {
        return (*qq)->score - (*pp)->score;
    }
}

/*
Sorts by score in ascending order, 
then by name in ascending order
*/
int ssa_sna(const void *p, const void *q) {
    record * const *pp = p;
    record * const *qq = q;
    int x;
    x = (*pp)->score - (*qq)->score;
    if (x != 0) {
        return x;
    } else if ((x = strcmp((*pp)->name.last, (*qq)->name.last)) != 0){
        return x;
    } else {
        return strcmp((*pp)->name.first, (*qq)->name.first);
    }
}

/*
Sorts by score in ascending order, 
then by name in descending order
*/
int ssa_snd(const void *p, const void *q) {
    record * const *pp = p;
    record * const *qq = q;
    int x;
    x = (*pp)->score - (*qq)->score;
    if (x != 0) {
        return x;
    } else if ((x = strcmp((*qq)->name.last, (*pp)->name.last)) != 0){
        return x;
    } else {
        return strcmp((*qq)->name.first, (*pp)->name.first);
    }
}

/*
Sorts by score in ascending order, 
then by name in descending order
*/
int ssd_sna(const void *p, const void *q) {
    record * const *pp = p;
    record * const *qq = q;
    int x;
    x = (*qq)->score - (*pp)->score;
    if (x != 0) {
        return x;
    } else if ((x = strcmp((*pp)->name.last, (*qq)->name.last)) != 0){
        return x;
    } else {
        return strcmp((*pp)->name.first, (*qq)->name.first);
    }
}

/*
Sorts by score in ascending order, 
then by name in descending order
*/
int ssd_snd(const void *p, const void *q) {
    record * const *pp = p;
    record * const *qq = q;
    int x;
    x = (*qq)->score - (*pp)->score;
    if (x != 0) {
        return x;
    } else if ((x = strcmp((*qq)->name.last, (*pp)->name.last)) != 0){
        return x;
    } else {
        return strcmp((*qq)->name.first, (*pp)->name.first);
    }
}