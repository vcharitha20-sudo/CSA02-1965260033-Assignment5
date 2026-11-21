#include <stdio.h>
typedef struct {int group_code,units;} Stock;
int update(FILE *f,int index,int units) {
    Stock s;long offset;
    if(index<0)return 0;
    offset=(long)index*(long)sizeof s;
    if(fseek(f,offset,SEEK_SET)!=0||fread(&s,sizeof s,1,f)!=1)return 0;
    s.units=units;
    if(fseek(f,offset,SEEK_SET)!=0||fwrite(&s,sizeof s,1,f)!=1)return 0;
    return fflush(f)==0;
}
int main(void) {Stock s[]={{1,10},{2,20},{3,30}};FILE *f=tmpfile();int i;
    if(!f){perror("tmpfile");return 1;}
    if(fwrite(s,sizeof s[0],3,f)!=3){perror("write");fclose(f);return 1;}
    printf("Updated: %d\n",update(f,1,25));rewind(f);
    for(i=0;i<3;i++)if(fread(&s[i],sizeof s[i],1,f)==1)printf("%d:%d ",s[i].group_code,s[i].units);
    puts("");fclose(f);return 0;
}
