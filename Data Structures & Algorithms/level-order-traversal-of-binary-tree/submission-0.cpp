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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> temp;
        int cnt =1;
        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();
            if(currNode == nullptr){
                ans.push_back(temp);
                temp.clear();
                cnt=0;
            }
            if(cnt==0){
                if(!q.empty())  q.push(nullptr);
                cnt = 1;
            }

            if(currNode) temp.push_back(currNode->val);

            if(currNode){
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
            }
        }

        return ans;
    }
};
