#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
typedef vector<int> vi;
class SegmentTree{
    vi st,A;
    int n;
    int left(int p){
        return (p<<2);
    }
    int right(int p){
        return (p<<2)+1;
    }
    void build(int p,int L,int R){
        if(L==R)
            st[p]=L;
        else{
            int mid= (L+R)/2;
            build(left(p),L,mid);
            build(right(p),mid+1,R);
            int p1=st[left(p)],p2=st[right(p)];
            st[p]= (A[p1]>=A[p2]) ? p1:p2;
        }
    }
    int rmaxq(int p,int L,int R,int i,int j){
        if(i>R || j<L)
            return -1;
        if(L>=i && R<=j)
            return st[p];
        int mid= (L+R)/2;
        int p1=rmaxq(left(p),L,mid,i,j);
        int p2=rmaxq(right(p),mid+1,R,i,j);
        if(p1==-1)
            return p2;
        if(p2==-1)
            return p1;
        return (A[p1]>=A[p2])? p1:p2;
    }
    public:
    SegmentTree(const vi &_A){
        A = _A; n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    int rmaxq(int i,int j){
        return rmaxq(1,0,n-1,i,j);
    }
};

int main(){
    int arr[] = { 18, 17, 13, 19, 15, 11, 20 };
    vi A(arr, arr + 7);
    SegmentTree st(A);
    printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
    printf("              A is {18,17,13,19,15, 11,20}\n");
    printf("rmaxq(1, 3) = %d\n", st.rmaxq(1, 3));
    printf("rmaxq(4, 6) = %d\n", st.rmaxq(4, 6));
    printf("rmaxq(3, 4) = %d\n", st.rmaxq(3, 4));
    printf("rmaxq(0, 0) = %d\n", st.rmaxq(0, 0));
    printf("rmaxq(0, 1) = %d\n", st.rmaxq(0, 1));
    printf("rmaxq(0, 6) = %d\n", st.rmaxq(0, 6));

    printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
    printf("Now, modify A into {18,17,13,19,15,100,20}\n");
    printf("These values do not change\n");
    printf("rmaxq(1, 3) = %d\n", st.rmaxq(1, 3));
    printf("rmaxq(3, 4) = %d\n", st.rmaxq(3, 4));
    printf("rmaxq(0, 0) = %d\n", st.rmaxq(0, 0));
    printf("rmaxq(0, 1) = %d\n", st.rmaxq(0, 1));
    printf("These values change\n");
    printf("rmaxq(0, 6) = %d\n", st.rmaxq(0, 6));
    printf("rmaxq(4, 6) = %d\n", st.rmaxq(4, 6));
    printf("rmaxq(4, 5) = %d\n", st.rmaxq(4, 5));

    return 0;
}
