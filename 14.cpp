#include<iostream>
#include<vector>
using namespace std;

//无大数越界情况
class Solution1 {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1,0);
        if(n <=3) return n-1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i<= n ;++i){
            dp[i] = max(dp[i-3]*3,dp[i-2]*2);
        } 
        return dp[n];
    }
};

//有大数越界情况，采用贪心算法，当n>4时，贪3比贪2要更优，当n = 4时两个2比一个3更优。
class Solution2 {
public:
    int cuttingRope(int n) {
        if(n <= 3) return n-1;
        long long res = 1;
        if(n == 4) return 4;
        while(n>4){
            //cout<<res<<endl;
            res = res*3%1000000007;
            n-=3;
        }
        return (int)(res*n%1000000007);
    }
};

int main(){
    return 0;
}