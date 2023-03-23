#include<stack>
#include<iostream>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    string expression;
    char temp;
    bool valid=true;
    stack<char> parentheses;
    cout<<"Enter an expression : ";
    getline(cin,expression);
    R(i,0,expression.size(),1){
        if(expression[i]=='(' || expression[i]=='{' || expression[i]=='['){
            parentheses.push(expression[i]);
        }
        if(expression[i]==')' || expression[i]=='}' || expression[i]==']'){
            if(parentheses.size()==0)
                valid=false;
            else{
                temp=parentheses.top();
                parentheses.pop();
                if(expression[i]==')' && (temp=='{'||temp=='['))
                    valid=false;
                if(expression[i]=='}' && (temp=='('||temp=='['))
                    valid=false;
                if(expression[i]==']' && (temp=='('||temp=='{'))
                    valid=false;
            }
        }
    }
    if(parentheses.size()>0)
        valid=false;
    if(valid)
        cout<<"\n Valid expression";
    else
        cout<<"\n Invalid expression";
}
