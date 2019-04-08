#include <iostream>
#define INT_MAX +2147483647
using namespace std;

void print(int parent[],int v,int weights[][100]){

	for(int i=1;i<v;i++){
		printf("%d-%d\tWeight: %d\n",parent[i],i,weights[i][parent[i]]);
	}
}
int min_extract(int key[],int processed[],int v){
    int mi_value=INT_MAX;
    int mi_index=-1;
    for(int i=0;i<v;i++){
        if(key[i] < mi_value && processed[i]==0){
            mi_value=key[i];
            mi_index=i;
        }
    }
    return mi_index;
}
void prim_mst(int weights[][100],int v){
    int parent[100];
    int key[100];
    int processed[100];
    for(int i=0;i<v;i++){
        key[i]=INT_MAX;
        processed[i]=0;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<v-1;i++){
        int u=min_extract(key,processed,v);
        processed[u]=1;
        for(int j=0;i<v;i++){
            if(key[j]>weights[u][j] && processed[j]==0 && weights[u][j]!=0){
                parent[j]=u;
                key[i]=weights[u][j];
            }
        }
    }
    print(parent,v,weights);
}
int main(){
    int v;
    int weights[100][100];
    cout << "Enter the no. of vertices " << endl;
    cin >> v;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout << "Enter the weight between (" << i+1 << "-" << j+1 << ") if no connect then -1" << endl;
            cin >> weights[i][j];
            if (weights[i][j]==-1){
                weights[i][j]=INT_MAX;
        }
    }
}
prim_mst(weights,v);
}
