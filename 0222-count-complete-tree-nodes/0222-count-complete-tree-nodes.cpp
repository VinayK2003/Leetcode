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

    int leftHeight(TreeNode* root){
        int cnt=0;

        while(root){
            cnt++;
            root=root->left;
        }
        return cnt;
    }
    int rightHeight(TreeNode* root){
        int cnt=0;

        while(root){
            cnt++;
            root=root->right;
        }
        return cnt;
    }

    int countNodes(TreeNode* root) {
        // A complete binary tree has 2 rules:
        // -> Every level except the last is completely filled.
        // -> The last level is filled from left to right, with no gaps.

        int cnt=0;
        if(!root) return cnt;
        
        int left= leftHeight(root);
        int right=rightHeight(root);

        if(left==right) return (1<<left)-1;

        return 1+countNodes(root->left)+countNodes(root->right);

    }
};