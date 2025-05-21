// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void solve(int n,int arr[],int i){
    // base case
    if(i==n){
        print(arr,n);
        return;
    }
    arr[i]=0;
    solve(n,arr,i+1);
     arr[i]=1;
    solve(n,arr,i+1);
}
int main() {
    int n=2;
    int arr[n];
    solve(n,arr,0);
    return 0;
}

// for n=2 the output is
0 0 
0 1 
1 0 
1 1 
