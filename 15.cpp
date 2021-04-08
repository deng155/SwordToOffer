#include<iostream>
using namespace std;

//该方法最优，最常见的计算二进制1个数方案
class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n>0){
            res++;
            //每次操作会将从低位开始计算的第一个1转为0;
            n&=n-1;
        }
        return res;
    }
};

//O(logn)复杂度,容易理解
class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n>0){
            res++;
            n&=n-1;
        }
        return res;
    }
};

int main(){
    return 0;
}