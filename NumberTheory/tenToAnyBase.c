#include<stdio.h>
int main(){
  int toBase,len;
  char Num[80];
  long long N;
  printf("Please Enter the number and the Base (2-16) to convert.\n");
  printf("Number: ");
  scanf("%lld",&N);
  printf("Base : ");
  scanf("%d",&toBase);
  long long q=N;
  len=0;
  while(q){
    int rem= q%toBase;
    if(rem>9)
      Num[len++]= 'A'+ rem-10;
    else
      Num[len++]= '0'+ rem;
    q=q/toBase;
  }
  printf("%lld converted to base %d = ",N,toBase);
  for(int i=len-1;i>=0;i--)
    putchar(Num[i]);
  putchar('\n');
}
