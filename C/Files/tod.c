#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
	FILE *fp;
	char ch;
	if(argc!=2){
		printf("You forgot to enter the filename.\n");
		exit(1);
	}
	if((fp=fopen(argv[1],"r"))==NULL){
		printf("Cannot open file.\n");
		exit(1);
	}
	ch = getc(fp);
	while (ch!=EOF) {
		putchar(ch);
		ch = getc(fp);
	}
	fclose(fp);
	return 0;
}