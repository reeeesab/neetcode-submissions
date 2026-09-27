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
    int getMax(TreeNode* root, int &maxi){
        if(!root) return 0;

        int leftMax = getMax(root->left, maxi);
        int rightMax= getMax(root->right, maxi);
        leftMax = leftMax < 0 ? 0: leftMax;
        rightMax = rightMax < 0? 0: rightMax;
        maxi=max(maxi, leftMax+rightMax+root->val);

        return root->val+max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int temp = getMax(root, maxi);
        return maxi;
    }
};
