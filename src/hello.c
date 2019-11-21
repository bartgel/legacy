#include "signs.h"
#include "httpd.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

char* getPort(char* port, size_t portSize, int argnum, char** args) {
	memset(port,0,portSize);
	strncpy(port, argnum < 3 ? "8080": args[2], portSize -1);
	return port;
}

int main(int argnum, char** args)
{
	char filename[300];
	char port[10];
	getFileName(filename,sizeof(filename),argnum,args);
	getPort(port,sizeof(port),argnum,args);
    serve_forever(port,filename);
    return 0;
}

int readHelloWorld(char* filename) {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) return -1;

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("%s", line);
    }

    fclose(fp);
    if (line)
        free(line);
    return 0;
}



void route(char* filename)
{
    ROUTE_START()

    ROUTE_GET("/")
    {
	FILE* fp = fopen(filename,"r");
	char buff[255];
        printf("HTTP/1.1 200 OK\rcontent-type: text/plain\r\n\r\n");
	if (readHelloWorld(filename) != 0) {
		default_hello();
	}

    }

    /*ROUTE_POST("/")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("Wow, seems that you POSTed %d bytes. \r\n", payload_size);
        printf("Fetch the data using `payload` variable.");
    }*/
  
    ROUTE_END()
}
