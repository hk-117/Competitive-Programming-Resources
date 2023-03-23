#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class UnionFind{
    private:
        vi p,rank,setSize;
        int numSets;
    public:
        UnionFind(int N){
            setSize.assign(N,1);
            rank.assign(N,0);
            p.assign(N,0);
            numSets=N;
            for(int i=0;i<N;i++){
                p[i]=i;
            }
        }
        int findSet(int i){
            return (p[i]==i)? i: (p[i]=findSet(p[i]));
        }
        bool isSameSet(int i,int j){
            return findSet(i)==findSet(j);
        }
        void unionSet(int i,int j){
            if(!isSameSet(i,j)){
                numSets--;
                int x=findSet(i),y=findSet(j);
                if(rank[x]>rank[y]){
                    p[y]=x;
                    setSize[x]+=setSize[y];
                }
                else{
                    p[x]=y;
                    setSize[y]+=setSize[x];
                    if(rank[x]==rank[y])
                        rank[y]++;
                }
            }
        }
        int numDisjointSets(){
            return numSets;
        }
        int sizeOfSet(int i){
            return setSize[findSet(i)];
        }
};

int main(){
    cout<<" Assume that there are 5 disjoint sets initially"<<endl;
    UnionFind UF(5);
    cout<<" Total disjoint: "<<UF.numDisjointSets()<<endl;
    UF.unionSet(0,1);
    cout<<" Total disjoint: "<<UF.numDisjointSets()<<endl;
    UF.unionSet(2,3);
    cout<<" Total disjoint: "<<UF.numDisjointSets()<<endl;
    UF.unionSet(4,3);
    cout<<" Total disjoint: "<<UF.numDisjointSets()<<endl;
    cout<<" isSameSet(0,3)="<< UF.isSameSet(0,3)<<endl;
}
