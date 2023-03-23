#include<stack>
#include<iostream>
using namespace std;

int main(){
    int arr[10];
    int val,n;
    stack<int> stk;
    cout<<"\n Enter the number of elements in the array: ";
    cin>>n;
    cout<<"\n Enter the elements of the array :";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        stk.push(arr[i]);
    for(int i=0;i<n;i++){
        int val=stk.top();
        stk.pop();
        arr[i]=val;
    }
    cout<<"\n The reversed array is : ";
    for(int i=0;i<n;i++)
        cout<<"\n "<< arr[i];
    return 0;
}
