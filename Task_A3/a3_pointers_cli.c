#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *lowest(int *a,int n) {int i,*best=a;if(n<=0)return NULL;for(i=1;i<n;i++)if(a[i]<*best)best=&a[i];return best;}
int main(int argc,char **argv) {
    int stock[8]={8,4,12,7,9,3,11,5};int *p=lowest(stock,8);
    printf("Minimum stock: %d (index %ld)\n",*p,(long)(p-stock));
    if(argc==1){puts("Usage: program find O+ | program issue A- 2");return 0;}
    if(argc==3 && strcmp(argv[1],"find")==0){printf("Requested group: %s\n",argv[2]);return 0;}
    if(argc==4 && strcmp(argv[1],"issue")==0){char *end;long qty=strtol(argv[3],&end,10);if(*end=='\0'&&qty>0){printf("Requested issue: %s %ld\n",argv[2],qty);return 0;}}
    fputs("Invalid arguments\n",stderr);return 1;
}
