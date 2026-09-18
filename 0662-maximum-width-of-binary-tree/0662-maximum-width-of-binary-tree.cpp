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

    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        ll maxi=0;
        if(!root) return maxi;
        // {Node , index}  where 
        // Left child index=2*idx+1;
        // Right child index=2*idx+2;
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});

        while(!q.empty()){
            ll n=q.size();
            auto a=q.front();
            auto b=q.back();

            maxi=max((int)maxi,(int)(b.second-a.second+1));
            for(int i=0;i<n;i++){
                auto p=q.front();
                q.pop();
                ll ind=p.second;
                if(p.first->left) q.push({p.first->left,2*ind+1});
                if(p.first->right) q.push({p.first->right,2*ind+2});
            }
        }
        return maxi;
    }
};