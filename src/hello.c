#include "signs.h"
#include <stdio.h>
#include <string.h>

int default_hello(void) {
	exm(0);
	h(1);
	e(0);
	for (int i =0; i <2; i++) l(0);
	o(0);
	spa(0);
	w(0);
	o(0);
	r(0);
	l(0);
	d(0);
	exm(0);
	cr(0);
}

char* getFileName(char* filename, size_t fileSize, int argnum, char** args) {
	memset(filename, 0, fileSize);
	strcpy(filename,"conf/");
        strncat(filename, argnum == 1 ? "default.txt": args[1],fileSize -1);
	return filename;
}

int main(int argnum, char** args) {
	char filename[300];
	FILE* fp = fopen(getFileName(filename,sizeof(filename),argnum,args),"r");
	char buff[255];
	if (fp != 0) {
		memset(buff, 0, sizeof(buff));
		fgets(buff,sizeof(buff) -1,fp);
		printf("%s",buff);
		fclose(fp);
		return 0;
	}
	default_hello();
}
