#include<iostream>
#include<vector>
using namespace std;

//题12
//DFS暴力
class Solution1 {
public:
    int minArray(vector<int>& numbers) {
        if(numbers[0]<numbers[numbers.size()-1]){
            return numbers[0];
        }
        return QuikeSort(numbers,0,numbers.size()-1);
    }
    int QuikeSort(vector<int>& numbers ,int begin ,int end){
        if(begin >= end){
            return numbers[begin];
        }
        int mid = begin+(end-begin)/2;
        if(numbers[mid] >numbers[end]){
            return QuikeSort(numbers,mid+1,end);
        } 
        else if(numbers[mid]<numbers[begin]){
            return QuikeSort(numbers,begin,mid);
        }
        else{
            return QuikeSort(numbers,begin,end-1);
        }
    }
};


//题13
//DFS暴力 
class Solution2 {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        return dfs(m,n,k,0,0,visited);
    }
private:
    int dfs(int m ,int n ,int k ,int x ,int y,vector<vector<bool>> &visited){
        if(x>=m||y>=n||(x%10+x/10+y%10+y/10)>k||visited[x][y] == true){
            return 0;
        }
        visited[x][y] =true;
        return 1+dfs(m,n,k,x+1,y,visited)+dfs(m,n,k,x,y+1,visited);
    }
};

int main(){
    Solution1 s1;
    vector<int> nums = {4,4,5,6,7,8,1,1,3};
    cout<<s1.minArray(nums)<<endl;
}