#include<iostream>
using namespace std;
int abss(int i);
double abss(double d);
long abss(long l);
int main(){
    cout<< abss(-10) <<endl;
    cout<< abss(-11.0) <<endl;
    cout<< abss(-9L) <<endl;
    return 0;
}
int abss(int i){
    cout<<"Using integer abss()\n";
    return i<0 ? -i : i;
}
double abss(double d){
    cout<<"Using double abss()\n";
    return d<0.0 ? -d:d;
}
long abss(long l){
    cout<< "Using long abss()\n";
    return l<0 ? -l:l;
}
