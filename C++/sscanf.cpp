#include<bits/stdc++.h>
using namespace std;

int main(){
    string inp;
    getline(cin,inp);
    int tmno,pnm,subt;
    char status;
    sscanf(inp.c_str(),"%d %d %d %c\n",&tmno,&pnm,&subt,&status);
    cout<<tmno<<"\t"<<pnm<<"\t"<<subt<<"\t"<<status<<endl;
}
