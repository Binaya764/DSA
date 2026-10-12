#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int c, int minAllowed){ //check whether the cows can be assigned min distance 
    int cow =1, lastPos = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]-lastPos >= minAllowed){
            cow++;
            lastPos = arr[i];
        }
        if(cow == c){
            return true;
        }
    }
    return false;

}


//calcuates the largest possible min distance between two cows
int largestMinDistance(vector<int> &arr, int stalls, int cows){
   sort(arr.begin(),arr.end()); //sorting the array

    int start = 1, end = arr[stalls-1]-arr[0], ans = -1;
    while(start<= end){
        int mid = start+(end-start)/2;
        if(isPossible(arr,stalls,cows,mid)){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    int n = 5, c = 3;
    vector<int> arr = {1,2,8,4,9};
    cout<<largestMinDistance(arr,n,c)<<endl;
    return 0;

}