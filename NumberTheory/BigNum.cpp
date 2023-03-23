#include<bits/stdc++.h>
using namespace std;

string BigNumDiv(string number,int divisor){
  string ans;
  int idx=0;
  int temp=number[idx++]-'0';
  while(temp<divisor){
    temp=temp*10 +(number[idx++]-'0');
  }
  while(number.size()>=idx){
    ans+= (temp/divisor) + '0';
    temp = (temp%divisor)*10 +number[idx++]-'0';
  }
  if(ans.length()==0)
    return "0";
  return ans;
}

int BigMod(string num,int a){
  int res=0;
  for(int i=0;i<num.length();i++){
    res= (res*10 + (int) num[i] -'0')%a ;
  }
  return res;
}

int main(){
}
