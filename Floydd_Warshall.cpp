#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MAX 2147483647
using namespace std;
void floydd_warshall(int a[][100],int v){
    for(int k=0;k<v;k++){
        for(int j=0;j<v;j++){
            for(int i=0;i<v;i++){
                if( (a[i][k]+a[j][k]<a[i][j]) && (a[i][k]+a[k][j]>0)){
                    a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
    }
}

int main()
{
cout << "Enter the Number of Vertices" << endl;
int v;
int a[100][100];
cin >> v;

for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
        cout << "Enter the weight of between " << i+1 << "-" <<j+1<< " vertices (-1 if not connecting):" << endl;
            cin >> a[i][j];
            if(a[i][j]==-1){
                a[i][j]=INT_MAX;
}
}
}
floydd_warshall(a,v);
cout << "Resultant Matrix " << endl;
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			if(a[i][j]==INT_MAX){
				cout << "INF\t" ;
			}
			else{
			 cout << a[i][j] <<"    ";     
			}
		}
		cout << "\n";
	}
	return 0;
}
