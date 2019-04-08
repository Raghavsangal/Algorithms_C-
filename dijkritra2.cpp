#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;
map<int,list<pair<int,int>>> m;
int q;
void addEdge(int u,int v,int w){
    m[u].push_back(make_pair(v,w));
    m[v].push_back(make_pair(u,w));
}
void dijkstra(int src){
    map<int,int> dist;
    for(auto j:m){
      dist[j.first] = +2147483647;
    }
    set<pair<int,int>> s;
    dist[src]=0;
    s.insert(make_pair(0,src));

    while(!s.empty()){
        auto p=*(s.begin());
        int node=p.second;
        int nodedistance=p.first;
        s.erase(s.begin());
        for(auto childnode :m[node]){
            if(nodedistance+childnode.second<dist[childnode.first])
            {
                int dest=childnode.first;
                auto f=s.find(make_pair(dist[dest],dest));
                if(f!=s.end()){
                    s.erase(f);
                }
                dist[dest]=nodedistance+childnode.second;
                s.insert(make_pair(dist[dest],dest));
            }

        }

    }
for(int i=1;i<=q;i++){
    if(i!=src){
        if(dist[i]==0){
            cout << -1 << " ";
        }
        else{
    cout <<dist[i]<< " ";
        }
}
}
}
int main(){
    int t;
    cin >>t;
    for(int k=0;k<t;k++){
        int n;
        cin >> q>> n;
        for(int i=0;i<n;i++){
            int u,v,w;
            cin >> u >> v >> w;
            addEdge(u,v,w);
        }
        int s;
        cin >>s;
        dijkstra(s);
    }
}
