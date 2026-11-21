#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv) {
    char name[32];int c;size_t len;
    if(argc!=2 || (strcmp(argv[1],"O+")!=0 && strcmp(argv[1],"A+")!=0 && strcmp(argv[1],"B-")!=0)) {
        fprintf(stderr,"Usage: %s O+|A+|B-\n",argv[0]);return 1;
    }
    printf("Enter donor name (max 31 characters): ");
    if(!fgets(name,sizeof name,stdin)){fputs("Input error\n",stderr);return 1;}
    len=strcspn(name,"\n");
    if(name[len]=='\n')name[len]='\0';
    else {while((c=getchar())!='\n'&&c!=EOF){} if(len==sizeof name-1){fputs("Name too long; rejected safely\n",stderr);return 1;}}
    printf("Accepted: %s (%s)\n",name,argv[1]);
    return 0;
}
