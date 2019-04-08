#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binary_search(int a[],int k,int l,int mid, int r){
    if(a[mid]==k){
        return mid;
    }
    else if(a[mid]>k){
       return binary_search(a,k,l,l+mid/2,mid);
    }
    else {
       return binary_search(a,k,mid,mid+r/2,r);
    }
}
int main()
{
    int n,k;
    int *a=(int *)malloc(51200*sizeof(int));
    cout << "Enter Size of Array" << endl;
    cin >> n;
    cout << "Enter the Elements" << endl;
    for(int i=0; i<n; i++){
        int b;
        cin >> b;
        a[i]=b;
    }
    sort(a,a+n);
    cout << "Enter the element to find" << endl;
    cin >> k;
    int index;
    index=binary_search(a,k,0,n/2,n);
    cout << "Element found at: "<< endl;
    cout << index << endl;
    return 0;
}