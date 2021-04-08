#include<iostream>
#include<vector>
#include<string>
using namespace std;

void ReplaceEmpty(string s){
    int count = 0;
    int len = s.size();
    for(int i = 0;i<len;++i){
        if(s[i] == ' '){
            count++;
        }
    }
    s.resize(2*count+len);
    int right = 2*count+len-1;
    for(int i = len-1;i>=0;--i){
        if(s[i] == ' '){
            s[right] = '0';
            s[right-1] = '2';
            s[right-2] = '%';
            right-=3;
        }
        else{
            s[right] = s[i];
            right-=1;
        }
    }
    cout<<s<<endl;
}

int main(){
    string s = "hello world";
    ReplaceEmpty(s);
    return 0;
}