#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int bs[1000005];

void mod_sieve(ll upb){
  ll sieve_size=upb+1;
  bs[0]=bs[1]=1;
  for(ll i=2;i<=sieve_size;i++){
    if(bs[i]==0){
      for(ll j=i;j<=sieve_size;j+=i) 
        bs[j]++;
    }
  }
}

int main(){
  ll N;
  mod_sieve(1000000);
  while(scanf("%lld",&N)==1 && N){
  }
}
