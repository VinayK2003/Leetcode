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

    TreeNode* helper(TreeNode* root, int key){
        if(!root->left) return root->right;
        if(!root->right) return root->left;

        TreeNode*right=root->right;
        TreeNode* last= lastChild(root->left);
        last->right=right;
        return root->left;
    }

    TreeNode* lastChild(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val==key){
            return helper(root,key);
        }

        TreeNode* dummy=root;
        while(root){
            //if key is in left
            if(root->val>key){  
                // We are checking this way coz we need the parent of key node
                if(root->left && root->left->val==key){
                    root->left=helper(root->left,key);
                    break;
                }else{
                    root=root->left;
                }
            }
            //if key is in right
            else{
                    if(root->right && root->right->val==key){
                        root->right=helper(root->right,key);
                        break;
                    }
                    else{
                        root=root->right;
                    }
            }
        }
        return dummy;
    }
};