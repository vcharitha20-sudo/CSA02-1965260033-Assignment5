#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct {int id;char group[4];} Donor;
typedef struct {Donor *data;int size,capacity;} DonorList;
int add_donor(DonorList *list,int id,const char *group) {
    if(list->size==list->capacity) {
        int new_capacity=list->capacity?list->capacity*2:2;Donor *p;
        if(list->capacity>INT_MAX/2)return 0;
        p=realloc(list->data,(size_t)new_capacity*sizeof(Donor));
        if(p==NULL)return 0;
        list->data=p;list->capacity=new_capacity;
    }
    list->data[list->size].id=id;
    strncpy(list->data[list->size].group,group,3);
    list->data[list->size].group[3]='\0';
    list->size++;return 1;
}
int main(void) {
    DonorList list={NULL,0,0};const char *groups[]={"O+","A+","B-","AB+","O-"};int i;
    for(i=0;i<5;i++) {
        if(!add_donor(&list,7001+i,groups[i])){fputs("Out of memory\n",stderr);free(list.data);return 1;}
        printf("added %d (%s): size = %d, capacity = %d\n",list.data[i].id,list.data[i].group,list.size,list.capacity);
    }
    free(list.data);return 0;
}
