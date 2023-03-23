#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& Graph,int nodes,int start){
    vector<int> visited(nodes,0);
    queue<int> q;
    q.push(start);
    visited[start]=1;
    cout<<"Path is: ";
    while(q.size()){
        start=q.front();
        q.pop();
        cout<<start<<"\t";
        for(int i=0;i<Graph[start].size();i++){
            if(!visited[Graph[start][i]]){
                q.push(Graph[start][i]);
                visited[Graph[start][i]]=1;
            }
        }
    }
}
int main(){
    cout<<"\n Enter nodes: ";
    int nodes;
    cin>>nodes;
    cout<<"\n Enter edges: ";
    int edges;
    cin>>edges;
    vector<vector<int>> Graph(nodes);
    for(int i=0;i<edges;i++){
        int v1,v2;
        cin>>v1>>v2;
        Graph[v1].push_back(v2);
    }
    bfs(Graph,nodes,0);
}
