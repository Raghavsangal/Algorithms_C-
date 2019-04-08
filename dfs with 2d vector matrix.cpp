
#include <bits/stdc++.h>
#include <string>
#include<vector>
#include<queue>
using namespace std;
int n;
vector<vector<int>> edges;
bool visited[60];
int v;
int a,b,d;
int parent[100];
queue<int> q;
// void path(int source,int parent[],int destination){
//     if(destination==source){
//  cout<<source<<" ";
//     }
//  else if(parent[destination]==0)    {       //Printing path from source to destination
//  cout<<"No Path"<<endl;  
//  } 
//  //according to the result of BFS
//  else
//  {
//   path(source,parent,parent[destination]);
//   cout<<destination<<" ";
//  }     
// }
void dfs(int s){
    
    
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
                dfs(c);
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
        //   edges[b][a]=1;
      }
    //   cin >>d;
//         for(int i=0;i<n;i++){
//       for(int j=0;j<n;j++){
//           cout << edges[i][j] <<" ";
//       }
//       cout << "\n";
//   }
  memset(visited,false,sizeof(visited));
  dfs(2);
//   int d;
  
//   path(1,parent,d);
//   for(int i=0;i<n;i++){
//     for(int child:parent[i]){
//         cout<< i <<":"<<child<<" ,";
//     }
//     cout<<"\n";
// }
}
  
  
INPUT:
4 6
0 1
0 2
1 2
2 0
2 3
3 3