#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    const char *aa= (const char*)a;
    const char *bb= (const char*)b;
    return strcmp(aa,bb);
}
int main(){
    int i;
    char words[5][10]={"car","bee","ant","zee","auxiliary"};
    qsort(words,5,sizeof(words[0]),cmp);
    for(i=0;i<5;i++){
        puts(words[i]);
    }
}
