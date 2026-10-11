#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int noOfBooks, int students, int maxPages){
    int student = 1, pages = 0;
    for(int i = 0; i<noOfBooks; i++){
        if(arr[i]>maxPages){
            return -1;
        }
        if(pages + arr[i] <= maxPages){
            pages += arr[i];
        }else{
            student++;
            pages = arr[i];
        }
    }
    return student>students?false: true;
}

int allocateBooks(vector<int> &arr, int noOfBooks, int students){
    if(students>noOfBooks){
        return false;
    }


    int sum = 0;
    for(int i =0; i<noOfBooks; i++){
        sum += arr[i];
    }

    int ans = -1;
    int start = 0, end = sum;
    while(start<= end){
        int mid = start+(end-start)/2;
        if(isValid(arr,noOfBooks,students,mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
}


int main(){
    vector<int> arr ={2,1,3,4};
    int n = 4;
    int m = 2;
    int result= allocateBooks(arr,n,m);
    cout<<"The min number of pages allocated is "<< result<< endl;
    return 0;
}