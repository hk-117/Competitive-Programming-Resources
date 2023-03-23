#include<stdio.h>
#include<string.h>
#define mx 100005

int p[mx],rank[mx],setSize[mx];
int numSets;

void UnionFind(int N){
    int i;
    memset(setSize,1,sizeof(setSize));
    numSets=N;
    for(i=0;i<N;i++){
        p[i]=i;
    }
}

int findSet(int i){
    return (p[i]==i)? i: (p[i]=findSet(p[i]));
}

int isSameSet(int i,int j){
    return findSet(i)==findSet(j);
}

void unionSet(int i,int j){
    if(!isSameSet(i,j)){
        int x=findSet(i),y=findSet(j);
        numSets--;
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

int main(){
    puts(" Assume that there are 5 disjoint sets initially");
    UnionFind(5);
    printf(" Total disjoint: %d\n",numDisjointSets());
    unionSet(0,1);
    printf(" Total disjoint: %d\n",numDisjointSets());
    unionSet(2,3);
    printf(" Total disjoint: %d\n",numDisjointSets());
    unionSet(4,3);
    printf(" Total disjoint: %d\n",numDisjointSets());
    printf(" isSameSet(0,3)= %d\n",isSameSet(0,3));
}
