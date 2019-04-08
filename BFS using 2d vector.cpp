
#include <bits/stdc++.h>
#include <string>
#include<vector>
#include<queue>
using namespace std;
int n;
vector<vector<int>> edges;
bool visited[60];
int v;
int a,b;
vector <int> parent[100];
void bfs(){
    int s=1;
    queue<int> q;
    memset(visited,false,sizeof(visited));
    visited[s]=true;
    q.push(s);
    while(!q.empty()){
        int f=q.front();
        cout << f << " " ;
        q.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] and edges[f][i]==1){
                int c=i;
                visited[c]=true;
                q.push(c);
                parent[i].push_back(f);
            }
        }
    }
}
int main(){
  cin >> n >> v;
edges.assign(n, vector < int >(n, 0));
  for(int i=0;i<v;i++){
          cin >> a >>b;
          edges[a][b]=1;
          for bidirectional//edges[b][a]=1;
      }
        for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          cout << edges[i][j] <<" ";
      }
      cout << "\n";
  }
  bfs();
  for(int i=0;i<n;i++){
    for(int child:parent[i]){
        cout<< i <<":"<<child<<" ,";
    }
    cout<<"\n";
}
}
INPUT:
4 6

0 1

0 2

1 2

2 0

2 3

3 3
  
  
