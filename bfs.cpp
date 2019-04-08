#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
int n;
vector<int> adj[1000];
void bfs(int src){
    queue<int> q;
    q.push(src);
    bool *visited=new  bool[n+1]{0};
    visited[src]=true;
    while(!q.empty()){
        int p;
        p=q.front();
        cout << p << " ";
        q.pop();
        visited[p]=true;
        for(auto node:adj[p]){
            if(!visited[node]){
            q.push(node);
            visited[node]=true;
        }
        }
    }
}
int main(){
    
    cin >> n;
     //Array of Linked List
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    // for(int i=0;i<n-1;i++){
    //     for(auto child: adj[i])
    //     cout << child << endl ;
    
    // }
}
