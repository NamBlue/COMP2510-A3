#ifndef cmp_h
#define cmp_h
int sname_asc(const void *p, const void *q);
int sname_desc(const void *p, const void *q);
int sscore_asc(const void *p, const void *q);
int sscore_desc(const void *p, const void *q);
int sna_ssa(const void *p, const void *q);
int sna_ssd(const void *p, const void *q);
int snd_ssa(const void *p, const void *q);
int snd_ssd(const void *p, const void *q);
int ssa_sna(const void *p, const void *q);
int ssa_snd(const void *p, const void *q);
int ssd_sna(const void *p, const void *q);
int ssd_snd(const void *p, const void *q);
#endif