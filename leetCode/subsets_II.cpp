#include<iostream>
#include<vector>
using namespace std;

void allvector(vector<int> &arr, vector<int> &ans,int i , vector<vector<int>> &allsubset){
    if(i == arr.size()){
        allsubset.push_back(ans);
        return;
    }
    ans.push_back(arr[i]);
    allvector(arr,ans,i+1,allsubset);
    ans.pop_back();
    //should eleminate duplicate values
    int idx = i+1;
    while(idx<arr.size() && arr[idx]==arr[i]){
        idx++;
    }

    allvector(arr,ans,idx,allsubset);

}
int main(){
    vector<int> arr={1,2,2};
    vector<int> ans;
    vector<vector<int>> allsubset;
    int i = 0;
    allvector(arr,ans,i,allsubset);
    for(int j = 0; j<allsubset.size();j++){
        cout<<"{";
        for(int k = 0; k<allsubset[j].size(); k++){
            cout<< allsubset[j][k];
            cout<<" ";

        }
        cout<<"}"<<endl;

    }
    return 0;
}