#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<int,int> index;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i =0 ;i< n;i++){
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder,inorder,0,n-1,0,n-1);
    }

    TreeNode* myBuildTree(vector<int>& preorder,vector<int>& inorder,int pre_left,int pre_right,int in_left, int in_right){
        if (pre_left > pre_right) {
            return nullptr;
        }
        int pre_root = pre_left;
        int in_root = index[preorder[pre_root]];
        TreeNode * root = new TreeNode(preorder[pre_root]);
        int sizeof_left = in_root-in_left;
        
        root->left = myBuildTree(preorder,inorder,pre_left+1,pre_left+sizeof_left,in_left,in_root-1);

        root->right = myBuildTree(preorder,inorder,pre_left+sizeof_left+1,pre_right,in_root+1,in_right);

        return root;
    }

};

int main(){
    Solution S1;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = S1.buildTree(preorder,inorder);
    return 0;
}