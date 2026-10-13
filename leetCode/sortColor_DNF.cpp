#include<iostream>
#include<vector>
using namespace std;

//using DNF algorithm
vector<int> sortColor(vector<int> &arr){
    int n = arr.size();
    int low = 0, mid = 0, high = n-1;
    while(mid<= high){
        if(arr[mid]==0){
            swap(arr[low], arr[mid]);
            mid++;
            low++;


        }else if(arr[mid]==1){
            mid++;

        }else if(arr[mid]==2){
            swap(arr[high],arr[mid]);
            high--;

        }
    }
    return arr;
    

}

int main(){
    vector<int> arr = {2,0,2,1,1,0};
    vector<int> result = sortColor(arr);
    int n = arr.size();
    for(int i = 0; i<n ; i++){
        cout<<result[i]<<endl;
    }
    return 0;
}