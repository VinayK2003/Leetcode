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

//  2 3 4 5 6 7
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&s){
     if(!root) return;
        inorder(root->left,s);
        s.push_back(root->val);
        inorder(root->right,s);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>s;
        inorder(root,s);
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]+s[j]==k) return true;
            if(s[i]+s[j]>k)j--;
            else i++;
        }
        return false;
    }
};