#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MAX 2147483647
using namespace std;
int i,j;
int is_safe(int board[100][100],int row,int col,int n){
    for(int i=0;i<col;i++){
        if(board[row][i]==1){
            return 0;
    }
    }
    for ( i=row, j=col; i>=0 && j>=0; i--, j--) {
        
        if (board[i][j]==1) 
            return 0; 
    }
  
    
    for (i=row,  j=col; j>=0 && i<n; i++, j--) {
        if (board[i][j]==1) 
            return 0; 
    }
  
    return 1; 

}
        

int solve(int board[100][100],int col,int n){
    if(col>=n){
		return 1;
	}
    for(int i=0;i<n;i++){
        if(is_safe(board,i,col,n)==1){
            board[i][col]=1;
            if(solve(board,col+1,n)==1){
                return 1;
            }
            board[i][col]=0;
        }
    }
    return 0;
}
        

int main(){
    int board[100][100];
    int n;
    cout << "Enter the Value of N" << endl;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=0;
}
}
if(solve(board,0,n)==0){
    cout<<"Solution does not exist" << endl ;
}
else{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << board[i][j] << "    " ;
        }
        cout << "\n" ;
    }
}
    return 0;
}