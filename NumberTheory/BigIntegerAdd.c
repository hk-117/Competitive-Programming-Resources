#include<stdio.h>
#include<string.h>
#define max(a,b) (a)>(b)?(a):(b)

char numA[500],numB[500],sum[550];

int main(){
  int lenA,lenB,lenS=0;

  printf("Enter number A: ");
  fgets(numA,sizeof numA,stdin);
  lenA=strcspn(numA,"\n");
  numA[lenA]='\0';

  printf("Enter number B: ");
  fgets(numB,sizeof numB,stdin);
  lenB=strcspn(numB,"\n");
  numB[lenB]='\0';

  int carry=0,mx=max(lenA,lenB);

  for(int i=mx-1;i>=0;i--){
    int d = ((numA[i]-'0')+(numB[i]-'0')+carry)/10;
    sum[lenS++]= (((numA[i]-'0')+(numB[i]-'0')+carry)-10 * d)+'0';
    carry=d;
  }

  sum[lenS++]=carry+'0';

  printf("Sum is: ");
  for(int i=lenS-1;i>=0;i--){
    putchar(sum[i]);
  }
  putchar('\n');
}
