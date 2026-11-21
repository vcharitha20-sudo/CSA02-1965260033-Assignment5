#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {int id,age;char name[24],group[4];} Donor;
static Donor make_donor(int i) {Donor d;d.id=700000+i;d.age=18+i%48;snprintf(d.name,sizeof d.name,"Donor%d",i);snprintf(d.group,sizeof d.group,"O+");return d;}
static int run(int n) {
    FILE *t=tmpfile(),*b=tmpfile();clock_t a,z;int i,id,age;char name[24],group[4];Donor d;long text_bytes,binary_bytes;
    if(!t||!b){perror("tmpfile");if(t)fclose(t);if(b)fclose(b);return 0;}
    a=clock();for(i=0;i<n;i++){d=make_donor(i);if(fprintf(t,"%d %d %s %s\n",d.id,d.age,d.name,d.group)<0){perror("text write");goto fail;}}fflush(t);z=clock();printf("n=%d text write %.4fs ",n,(double)(z-a)/CLOCKS_PER_SEC);
    a=clock();for(i=0;i<n;i++){d=make_donor(i);if(fwrite(&d,sizeof d,1,b)!=1){perror("binary write");goto fail;}}fflush(b);z=clock();printf("binary write %.4fs ",(double)(z-a)/CLOCKS_PER_SEC);
    text_bytes=ftell(t);binary_bytes=ftell(b);printf("sizes %ld/%ld bytes\n",text_bytes,binary_bytes);
    rewind(t);a=clock();for(i=0;i<n;i++)if(fscanf(t,"%d %d %23s %3s",&id,&age,name,group)!=4){fputs("text read error\n",stderr);goto fail;}z=clock();printf("text read %.4fs ",(double)(z-a)/CLOCKS_PER_SEC);
    rewind(b);a=clock();for(i=0;i<n;i++)if(fread(&d,sizeof d,1,b)!=1){fputs("binary read error\n",stderr);goto fail;}z=clock();printf("binary read %.4fs\n",(double)(z-a)/CLOCKS_PER_SEC);
    fclose(t);fclose(b);return 1;
fail:fclose(t);fclose(b);return 0;
}
int main(void) {int n[]={10,1000,10000,100000};int i;for(i=0;i<4;i++)if(!run(n[i]))return 1;return 0;}
