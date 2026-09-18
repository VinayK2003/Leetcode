/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root) return ans;
        if(k==0) {
            ans.push_back(target->val);
            return ans;
        }
        parent(root);
        unordered_map<TreeNode*,int>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=1;

        while(!q.empty() && k > 0){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                // checking if left child exists and not visited
                if(node->left && vis[node->left]==0){
                    q.push(node->left);
                    vis[node->left]=1;
                    if(k==1){
                        ans.push_back(node->left->val);
                    }
                }
                // checking if right child exists and not visited
                if(node->right && vis[node->right]==0){
                    q.push(node->right);
                    vis[node->right]=1;
                    if(k==1){
                        ans.push_back(node->right->val);
                    }
                }
                // checking if parent exists and not visited
                if(mp.find(node)!=mp.end() && vis[mp[node]]==0){
                    q.push(mp[node]);
                    vis[mp[node]]=1;
                    if(k==1){
                        ans.push_back(mp[node]->val);
                    }
                }
            }
            k--;
        }
            return ans;
    }
};