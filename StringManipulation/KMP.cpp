#include<cstdio>
#include<cstring>
#define MAX_N 20
using namespace std;
char T[MAX_N],P[MAX_N];
int b[MAX_N],n,m;

void kmpPreprocess(){
  int i=0,j=-1;
  b[0]=-1;
  while(i<m){
    while(j>=0 && P[i]!=P[j]) j=b[j];
    i++;j++;
    b[i]=j;
  }
}

void kmpSearch(){
  int i=0,j=0;
  while(i<n){
    while(j>=0 && T[i]!=P[j]) j=b[j];
    i++;j++;
    if(j==m){
      printf("P is found at index %d in T\n",i-j);
      j=b[j];
    }
  }
}

int main(){
  puts("Enter the Text:");
  fgets(T,sizeof T,stdin);
  n=strcspn(T,"\n");
  puts("Enter the pattern:");
  fgets(P,sizeof P,stdin);
  m=strcspn(P,"\n");
  kmpPreprocess();
  kmpSearch();
}
