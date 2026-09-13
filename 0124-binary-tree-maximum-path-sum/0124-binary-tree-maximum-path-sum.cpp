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
    int maxSum;

    int solve(TreeNode* root){
        if(!root) return 0;

        int left= solve(root->left);
        int right=solve(root->right);

        int dono_acche_mil_gaye= left+right+root->val;

        int koi_ek_accha= max(left,right)+ root->val;

        int only_root_accha= root->val;

        maxSum=max({maxSum,dono_acche_mil_gaye,koi_ek_accha,only_root_accha});

        //Here the catch is, you wont return dono_acche_mil_gaye because you are simply declaring
        // the solution by considering both left and right  
        return max(only_root_accha,koi_ek_accha);
    }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);

        return maxSum;
    }
};