#include<iostream>
#include<vector>
using namespace std;

vector<int> Merge(vector<int> &arr1,int m, vector<int> &arr2 , int n){
    int idx= m+n-1;
    int i = m-1;
    int j = n-1;
    while(i>=0 && j>=0){
        if(arr1[i]>=arr2[j]){
            arr1[idx--]=arr1[i--];
        }else{
            arr1[idx--]=arr2[j--];
        }
    }
    while(j>=0){
        arr1[idx--]=arr2[j--];
    };
    return arr1;
}

int main(){
    vector<int> arr1= {1,4,6,7};
    vector<int> arr2= {2,2,8};
    int m = arr1.size();
    int n = arr2.size();
    vector<int> result = Merge(arr1,m,arr2,n);
    for(int i=0; i<=n+m-1;i++){
        cout<<arr1[i]<<endl;
        
    }
    return 0;
}