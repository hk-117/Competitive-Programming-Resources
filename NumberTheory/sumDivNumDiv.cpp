#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
bitset<10000010>bs;
vi Primes;

void sieve(ll upb){
  ll sieve_size=upb+1;
  bs.set();
  bs[0]=bs[1]=0;
  for(ll i=2;i<=sieve_size;i++){
    if(bs[i]){
      for(ll j=i*i;j<=sieve_size;j+=i) 
        bs[j]=0;
      Primes.push_back(i);
    }
  }
}

ll sumDiv(ll N){
  ll PF_idx=0,PF=Primes[PF_idx],ans=1;
  while(PF*PF <= N){
    ll power=0;
    while(N%PF == 0) {N/=PF;power++;}
    ans *= ((ll)pow((double)PF,power+1.0)-1)/(PF-1);
    PF=Primes[++PF_idx];
  }
  if(N!=1) ans *= ((ll)pow((double)N,2.0)-1)/(N-1);
  return ans;
}

ll numDiv(ll N){
  ll PF_idx=0,PF=Primes[PF_idx],ans=1;
  while(PF*PF <= N){
    ll power=0;
    while(N%PF == 0) {N/=PF;power++;}
    ans *= (power+1);
    PF=Primes[++PF_idx];
  }
  if(N!=1) ans *= 2;
  return ans;
}

int main(){
}
