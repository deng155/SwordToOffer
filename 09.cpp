#include<iostream>
#include<stack>
using namespace std;

class CQueue {
private:
    stack<int>s1;
    stack<int>s2;
public:
    CQueue() {
        while(!s1.empty()){
            s1.pop();
        }
        while(!s2.empty()){
            s2.pop();
        }
        cout<<"构造函数被调用"<<endl;
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        } 
        if (s2.empty()) {
            return -1;
        } else {
            int deleteItem = s2.top();
            s2.pop();
            return deleteItem;
        }

    }
    ~CQueue(){
        cout<<"析构函数被调用"<<endl;
    }
};

int main(){
    CQueue* obj = new CQueue();
    for(int i = 0;i<5;++i){
        obj->appendTail(i);
    }
    for(int i = 0;i<5;++i){
        int param_2 = obj->deleteHead();
        cout<<i<<endl;
    }
    delete obj;
    return 0;
}