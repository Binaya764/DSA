#include<iostream>
#include<vector>
using namespace std;

void getSubset(vector<int> &arr, vector<int> &ans, int i, vector<vector<int>> &allSubset){
    if(i == arr.size()){
        allSubset.push_back(ans);
        return;
    }
    ans.push_back(arr[i]);
    getSubset(arr,ans,i+1,allSubset);
    ans.pop_back();
    getSubset(arr,ans,i+1,allSubset);

}
int main(){
    vector<int> arr={1,2,3};
    vector<int> ans;
    vector<vector<int>> allSubset;
    int i =0;
    getSubset(arr,ans,i,allSubset);
    for(int j =0; j<allSubset.size();j++){
        cout<<"{";
        for(int k =0;k <allSubset[j].size();k++){
            cout<<allSubset[j][k]<< " ";
        }
        cout<<"}"<<endl;
    }
    return 0;
}