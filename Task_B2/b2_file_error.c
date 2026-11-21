#include <stdio.h>
int main(int argc,char **argv) {
    FILE *f;int c;
    if(argc!=2)
	{fprintf(stderr,"Usage: %s filename\n",argv[0]);return 1;}
    f=fopen(argv[1],"rb");
	if(!f){perror("fopen");return 1;}
    while((c=fgetc(f))!=EOF){}if(ferror(f)){perror("fgetc");fclose(f);return 1;}
    puts("File read successfully");
	fclose(f);
	return 0;
}
