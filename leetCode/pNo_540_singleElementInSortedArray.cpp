// SINGLE ELEMENT IN A SORTED ARRAY 
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int singleNonDuplicate(vector<int>& Arr){
        int size= Arr.size();
        if(size == 1) return Arr[0];
        

        
        int start =0, end = size-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(mid == 0 && Arr[0] != Arr[1]){
                return Arr[0];
            }
            if(mid == size-1 && Arr[size-1] != Arr[size-2]){
                return Arr[mid];
            }
            
            if (Arr[mid-1] != Arr[mid] && Arr[mid] != Arr[mid + 1]){
                return Arr[mid];
            }else{
                if(mid%2==0){
                    if(Arr[mid-1]== Arr[mid]){
                        end = mid-1;
                    }
                    else{
                        start = mid+1;
                    }
                }else{
                    if(Arr[mid-1]== Arr[mid]) {
                        start = mid+1;
                    }else{
                        end = mid-1;
                    }
                }
                
                
            }
            



            

        }
        return -1;


    }
};

int main(){
    Solution s;
    vector<int> arr = {1,1,2,3,3,4,4,8,8};
    int result = s.singleNonDuplicate(arr);
    cout<< "The single element is:"<< result<< endl;
    return 0;
}