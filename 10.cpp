#include<iostream>
using namespace std;

//斐波那契数列，简单DP递推。
class Solution1 {
public:
    int fib(int n) {
        if(n<=1) return n;
        int left = 0;
        int right =1;
        int res = 0;
        for(int i = 2;i<=n ;++i){
            res = (left+right)%1000000007;
            left = right;
            right = res;
        }
        return res;
    }
};

//跳台阶 
//一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
//与斐波那契数列解法完全一致，找到dp公式 dp[i] = dp[i-1]+dp[i-2];
class Solution2 {
public:
    int numWays(int n) {
        if(n<=1) return 1;
        int left = 1;
        int right =1;
        int res = 0;
        for(int i = 2;i< n;++i){
            res = (left+right)%1000000007;
            left = right;
            right = res;
        }
        return res;

    }
};

int main(){
    
    return 0;
}