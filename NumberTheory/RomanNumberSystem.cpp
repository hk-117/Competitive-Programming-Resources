#include<bits/stdc++.h>
using namespace std;

void AtoR(int A){
    map<int, string> cvt;
    cvt[1000] = "M"; cvt[900] = "CM"; cvt[500] = "D"; cvt[400] = "CD";
    cvt[100]  = "C"; cvt[90]  = "XC"; cvt[50]  = "L"; cvt[40]  = "XL";
    cvt[10]   = "X"; cvt[9]   = "IX"; cvt[5]   = "V"; cvt[4]   = "IV";
    cvt[1]= "I";
    map<int,string>::reverse_iterator i;
    for (i=cvt.rbegin();i != cvt.rend(); i++){
        while (A >= i->first) {
            printf("%s", ((string)i->second).c_str());
            A -= i->first; 
        }
    }
    printf("\n");
}

void RtoA(const char* R){
    map<char, int> RtoA;
    RtoA['I'] = 1;   RtoA['V'] = 5;   RtoA['X'] = 10;  RtoA['L'] = 50;
    RtoA['C'] = 100; RtoA['D'] = 500; RtoA['M'] = 1000;
    int value = 0;
    for (int i = 0; R[i]; i++){
        if (R[i+1] && RtoA[R[i]] < RtoA[R[i+1]]) {
            value += RtoA[R[i + 1]] - RtoA[R[i]];
            i++; 
        }
        else 
            value += RtoA[R[i]];
    }
    printf("%d\n", value);
}

int main(){
    string nm;
    while(cin>>nm){
        if(isdigit(nm[0])){
            AtoR(atoi(nm.c_str()));
        }
        else{
            RtoA(nm.c_str());
        }
    }
}
