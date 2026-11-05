#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &arr, int start, int mid, int end){
    int i = start, j = mid+1;
    vector<int> temp;
    int countInversion=0;
    while(i<=mid && j <= end){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j]);
            j++;
            countInversion += mid-i+1;
        }else{
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx =0; idx<temp.size(); idx++){
        arr[idx+start]= temp[idx];
    }
    

    return countInversion;
}

int mergeSort(vector<int> &arr, int start, int end){
    if(start>=end){
        return 0;
    }
    int mid = start+(end-start)/2;
    int leftArrayInversion = mergeSort(arr,start,mid);
    int rightArrayInversion = mergeSort(arr,mid+1,end);
    int inversionCount = merge(arr,start,mid,end);
    int TotalInversionCount = leftArrayInversion+rightArrayInversion+inversionCount;
    return TotalInversionCount;
}


int main(){
    vector<int> arr ={2,1,4,5,6,7,4};
    int start = 0;
    int end = arr.size()-1;
    int result = mergeSort(arr,start,end);
    cout<<"Total countInversion :"<<result<<endl;
    return 0;
}