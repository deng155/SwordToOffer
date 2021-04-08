#include<iostream>
#include<vector>
using namespace std;


//递归解法
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


//迭代解法
class Solution2 {
public:
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size()-1;
        if(numbers[left]<numbers[right]){
            return numbers[left];
        }
        while(left<right){
            int mid = (left+right)/2;
            cout<<mid<<endl;
            if(numbers[mid]>numbers[right]){
                left = mid+1;
            }
            else if(numbers[mid]<numbers[left]){
                right = mid;
            }
            else{
                right--;
            }
        }
        return numbers[left];
    }
};

int main(){
    vector<int> nums = {4,5,6,7,8,1,2,3};
    return 0;
}