#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>nums(n,0);
    unordered_set<int> hash;
    for(int i = 0;i<n;++i){
        cin>>nums[i];
    }
    for(int i = 0 ;i<n ;++i){
        if(hash.count(nums[i])>0){
            cout<<nums[i]<<endl;
            break;
        }
        hash.insert(nums[i]);
    }
    return 0;
}