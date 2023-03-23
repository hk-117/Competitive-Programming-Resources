#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	float a;
	char name[40];
}cust;
int main(int argc,char *argv[]){
	FILE *fp;
	cust.a= 21.53;
	strcpy(cust.name,"Zubayer");
	if(argc!=2){
		puts("You forgot to give the file name");
		exit(1);
	}
	if(fopen(argv[1],"wb+")==NULL){
		puts("Cannot open the file");
		exit(1);
	}
	fwrite(&cust, sizeof(struct node), 1, fp);
	fclose(fp);
	return 0;
}