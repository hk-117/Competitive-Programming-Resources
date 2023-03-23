#include<bits/stdc++.h>
using namespace std;

int main(){
    string inp;
    getline(cin,inp);
    char *c = new char[inp.size()+1];
    strcpy(c,inp.c_str());
    char *p =strtok(c,"#@");
    while(p!=NULL){
        cout<< p<<endl;
        p=strtok(NULL,"#@");
    }
}
