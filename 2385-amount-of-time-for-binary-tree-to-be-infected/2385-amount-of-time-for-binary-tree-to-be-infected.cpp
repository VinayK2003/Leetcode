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
    unordered_map<TreeNode*,TreeNode*>mp;

    void parent(TreeNode* root){
        if(!root) return;

        if(root->left) {
            mp[root->left]=root;
        }
        parent(root->left);

        if(root-> right){
            mp[root->right]=root;
        }
        parent(root->right);
    }

    TreeNode* find(TreeNode*root,int start){
        if(!root) return NULL;
        if(root->val==start) return root;
        TreeNode* left = find(root->left, start);
        if(left) return left;
        return find(root->right, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        parent(root);
        TreeNode* k=find(root,start);
        queue<TreeNode*> q;
        q.push(k);
        unordered_map<TreeNode*,int>vis;
        vis[k]=1;
        int cnt=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && vis[node->left]==0){
                    q.push(node->left);
                    vis[node->left]=1;
                }
                if(node->right && vis[node->right]==0){
                    q.push(node->right);
                    vis[node->right]=1;
                }
                if(mp.find(node)!=mp.end() && vis[mp[node]]==0){
                    q.push(mp[node]);
                    vis[mp[node]]=1;
                }
            }
            if(!q.empty()) cnt++;
        }
        return cnt;
    }
    
};