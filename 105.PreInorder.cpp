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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
        return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        auto k=std::find(inorder.begin(),inorder.end(),preorder[0]);
        vector<int> leftin(inorder.begin(),k);
        inorder=vector<int>(k+1,inorder.end());
        vector<int>leftpre(preorder.begin()+1,preorder.begin()+1+leftin.size());
        preorder=vector<int>(preorder.begin()+1+leftin.size(),preorder.end());
        root->left=buildTree(leftpre,leftin);
        root->right=buildTree(preorder,inorder);
        return root;
    }
};