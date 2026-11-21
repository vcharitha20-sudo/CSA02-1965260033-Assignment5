#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct {int *ids;size_t size,capacity;} List;
int append(List *l,int id) {
    if(l->size==l->capacity) {
        size_t cap=l->capacity?l->capacity*2:2;int *p;
        if(cap<l->capacity || cap>SIZE_MAX/sizeof(int))return 0;
        p=realloc(l->ids,cap*sizeof(int));if(!p)return 0;
        l->ids=p;l->capacity=cap;
    }
    l->ids[l->size++]=id;return 1;
}
int main(void) {List l={NULL,0,0};int i;for(i=0;i<10;i++){if(!append(&l,7001+i)){fputs("Out of memory\n",stderr);free(l.ids);return 1;}printf("size=%lu capacity=%lu\n",(unsigned long)l.size,(unsigned long)l.capacity);}free(l.ids);return 0;}
