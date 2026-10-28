#include<iostream>
#include<vector>
using namespace std;

bool binarysearch(vector<int> &arr, int target, int start, int end){
    if(start>end){
        return false;
    }
    int mid = start+(end-start)/2;
    
        if(arr[mid]== target){
            return true;
        }else if(arr[mid]<target){
            return binarysearch(arr,target,mid+1,end);
        }else{
            return binarysearch(arr,target,start,mid-1);
        }
    
    
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int start = 0;
    int end = arr.size()-1;
    int target = 1;
    if(binarysearch(arr,target,start,end)){
        cout<<"Target found"<<endl;
    }else{
        cout<<"Target not found"<<endl;
    }
    return 0;

}