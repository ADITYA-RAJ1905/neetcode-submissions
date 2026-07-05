/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* root,int maxi,int& c){
        if(!root){
            return;
        }
        if(root->val>=maxi){
            c++;
        }
        maxi=max(root->val,maxi);
        solve(root->left,maxi,c);
        solve(root->right,maxi,c);
    }
    int goodNodes(TreeNode* root) {
        int c=0;
        solve(root,INT_MIN,c);
        return c;
    }
};
