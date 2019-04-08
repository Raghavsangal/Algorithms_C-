#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;
map<int,list<pair<int,int>>>m;
void addEdge(int u,int v,int dist){
    m[u].push_back(make_pair(v,dist));
    m[v].push_back(make_pair(u,dist));
}
void printAdj(){
    for(auto j:m){
        cout << j.first << "->" ;
        for(auto l:j.second){
            cout <<"("<< l.first << "," << l.second << ")";
        }
        cout << endl;
    }
    
}
    void dijsktra(int src){
        
        unordered_map<int,int> dist;
        
        //Set all distance to infinity
        for(auto j:m){
            dist[j.first] = INT_MAX;
        }
        
        //Make a set to find a out node with the minimum distance
        set<pair<int, int> > s;
        
        dist[src] = 0;
        s.insert(make_pair(0,src));
        
        while(!s.empty()){
            
            //Find the pair at the front.
            auto p =   *(s.begin());
            int node = p.second;
            
            int nodeDist = p.first;
            s.erase(s.begin());
            
            
            //Iterate over neighbours/children of the current node
            for(auto childPair: m[node]){
                
                if(nodeDist + childPair.second < dist[childPair.first]){
                    
                    
                    //In the set updation of a particular is not possible
                    // we have to remove the old pair, and insert the new pair to simulation updation
                    int dest = childPair.first;
                    auto f = s.find( make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    
                    //Insert the new pair
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest],dest));
                    
                }
                
            }
        }
        //Lets print distance to all other node from src
        for(auto d:dist){
            
            cout<<d.first<<" is located at distance of  "<<d.second<<endl;
        }
        
        
    }
// void dijsktra(int src){
//     map<int,int>dist;
//     for(auto j: m){
//         dist[j.first]=INT_MAX;
//     }
//     set<pair<int,int>> s;
//     dist[src]=0; 
//     s.insert(make_pair(0,src));
//     while(!s.empty()){
//         auto p=*(s.begin());
//         int node=p.second;
//         int nodedistance=p.first;
//         s.erase(s.begin());
//         for (auto childpair:m[node]){
//             if(nodedistance+childpair.second < dist[childpair.first]){
//                 int dest=childpair.first;
//                 auto f=s.find(make_pair(dist[dest],dest));
//                 if(f!=s.end()){
//                     s.erase(f);
//                 }
//                 dist[dest]=nodedistance+childpair.second;
//                 s.insert(make_pair(dist[dest],dest));
//             }
//         }
//          for(auto d:dist){
//             cout<<d.first<<" is located at distance of  "<<d.second<<endl;
//         }
//     }
// }
int main(){
    int a,b;
    cin >> a >>b;
    for(int i=0;i<b;i++){
        int u,v,w;
        cin >> u >>v >> w;
        addEdge(u,v,w);
    }
    printAdj();
    dijsktra(1);
    
}
