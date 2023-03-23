#include<bits/stdc++.h>
using namespace std;

int main(){
    string inp;
    getline(cin,inp);
    string teamsplit;
    stringstream ss(inp);
    while(getline(ss,teamsplit,'@')){
         stringstream sss(teamsplit);
         string tmp;
         while(getline(sss,tmp,'#')){
             cout<<tmp<<endl;
         }
     }
}
//team a#1@3#team b >> input is that
