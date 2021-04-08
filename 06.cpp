#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;     
    ListNode(int x) : val(x), next(NULL) {}
};

//创建链表
ListNode* CreateNode(){
    int n;
    cin>>n;
    ListNode* root = new ListNode(0);
    ListNode* node = root;
    while(n>0){
        int temp;
        cin>>temp;
        node->next = new ListNode(temp);
        node = node->next;
        n--;
    }
    return root->next;
}

void PrintList(){
    ListNode *node = CreateNode();
    stack<int>st;
    while(node){
        st.push(node->val);
        node = node->next;
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    delete(node);
}

int main(){
    PrintList();
    return 0;
}