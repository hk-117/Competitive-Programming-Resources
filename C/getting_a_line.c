#include<stdio.h>
#include<string.h>
int main(){
    char line[100],name[10],tot[500];
    int total_line=5;
    while(total_line--){
        int i=0;
        while((line[i++]=getchar()) !='\n');
        line[i]='\0';
        strcat(tot,line);
    }
    puts("The line is:\t");
    puts(tot);
    scanf("%s",name);
    puts("Name is:\t");
    puts(name);
    return 0;
}
