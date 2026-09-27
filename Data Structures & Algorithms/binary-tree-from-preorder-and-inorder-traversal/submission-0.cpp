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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> &m){
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        int rootNumberPosInOrder = m[preorder[preStart]];
        TreeNode* root = new TreeNode(inorder[rootNumberPosInOrder]);



        root->left = build(preorder, preStart+1,preStart+ rootNumberPosInOrder - inStart, inorder, inStart, rootNumberPosInOrder-1, m);
        root->right = build(preorder, preStart+ rootNumberPosInOrder - inStart+1, preEnd, inorder, rootNumberPosInOrder+1, inEnd, m);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size()) return nullptr;
        unordered_map<int, int> m;
        for(int i =0 ; i<inorder.size();i++) m[inorder[i]] = i;

        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1,m); 
    }
};
