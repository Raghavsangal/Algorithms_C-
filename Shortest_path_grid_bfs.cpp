// #include<iostream>
#include <bits/stdc++.h>
#include<queue>
using namespace std;
#define mem(array, value)   memset(array, value, sizeof(array))
char grid[59][59];
bool visited[59][59];
vector <pair<int,int>> f,s;
int ans;
int n;
const int INF = 1e9+9;

int dx[] = {1, -1, 0, 0},dy[] = {0, 0, 1, -1};
int dist(int x1, int y1, int x2, int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

bool valid (int x, int y)
{
    
    return (x >= 1 && x <= n && y >= 1 && y <= n && grid[x][y] == '0' && !visited[x][y]);
}
void bfs(int x,int y, bool first){
    mem(visited,false);
    queue<pair<int,int>> q;
    if(first){
        f.push_back(make_pair(x,y));
    }
    else{
        s.push_back(make_pair(x,y));
    }
    visited[x][y]=true;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int ax,ay;
        ax=q.front().first;
        ay=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            x=ax+dx[i];
            y=ay+dy[i];
            if(valid(x,y)){
                visited[x][y]=true;
                q.push(make_pair(x,y));
                    if(first){
        f.push_back(make_pair(x,y));
             }
         else{
        s.push_back(make_pair(x,y));
             }
            }
        }
    }
    
}


int main(){
    cin >> n;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> grid[i][j];
        }
    }
    bfs(a,b,true);
    bfs(c,d,false);
        int ans = INF;
    for (auto t : f){
        for (auto r : s){
            ans = min(ans, dist(t.first, t.second, r.first, r.second));
        }
    }
    cout << ans << endl;
    return 0;
    
}