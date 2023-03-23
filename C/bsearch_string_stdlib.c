#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char *alph="abcdfghijklmnopqrstuvwxyz";
int comp(const void *ch,const void *s);
int main(){
    char ch;
    char *p;
    printf("Enter a character: ");
    ch=getchar();
    ch=tolower(ch);
    p = (char*) bsearch(&ch,alph,26,sizeof(ch),comp);
    if(p){
        printf("%c is in alphabet\n",*p);
    }
    else{
        printf("%c is not in alphabet\n",ch);
    }
    return 0;
}
int comp(const void *ch,const void *s){
    return *(char *) ch- *(char *)s;
}
