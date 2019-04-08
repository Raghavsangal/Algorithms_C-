#include <iostream>
#include <string>
using namespace std;
void LCS(string a,string b,int m,int n){
    int l[100][100];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                l[i][j]=0;
            }
            if(a[i-1]==b[j-1]){
                l[i][j]=l[i-1][j-1]+1;
            }
                else{
                l[i][j]=max(l[i-1][j],l[i][j-1]);
            }
        }
    }
    int index = 5;
  
   // Create a character array to store the lcs string 
   string lcs; 
//   lcs[index] = ''; // Set the terminating character 
  
   // Start from the right-most-bottom-most corner and 
   // one by one store characters in lcs[] 
   int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      // If current character in X[] and Y are same, then 
      // current character is part of LCS 
      if (a[i-1] == b[j-1]) 
      { 
          lcs[index-1] = a[i-1]; // Put current character in result 
          i--; j--; index--;     // reduce values of i, j and index 
      } 
  
      // If not same, then find the larger of two and 
      // go in the direction of larger value 
      else if (l[i-1][j] > l[i][j-1]) 
         i--; 
      else
         j--; 
   } 
  
   // Print the lcs 
   cout << "LCS of " << a << " and " << b << " is " << lcs; 
} 
int main(){
    string a,b;
    cout << "Enter the Strings"  ;
    cin >> a >> b;
    int m=a.size();
    int n=b.size();
    LCS(a,b,m,n);
}
