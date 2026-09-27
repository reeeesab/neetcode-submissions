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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int lastValueBeforeNull=0;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            lastValueBeforeNull = node?node->val:lastValueBeforeNull;
            if(!node) ans.push_back(lastValueBeforeNull);
            if(node && node->left)  q.push(node->left);
            if(node && node->right) q.push(node->right);
            if(!node && !q.empty()){
                q.push(nullptr);
            }
        }
        return ans; 
    }
};
