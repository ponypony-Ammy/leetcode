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
    TreeNode* helper(vector<int>&in,vector<int>&post,int inStart,int inEnd,int postStart,int postEnd,unordered_map<int,int> &mp)
    {
        if(inStart>inEnd||postStart>postEnd)
        return nullptr;
        TreeNode* root=new TreeNode(post[postEnd]);
        int rootin=mp[post[postEnd]];
        int leftsize=rootin-inStart;
        root->left=helper(in,post,inStart,rootin-1,postStart,postStart+leftsize-1,mp);
        root->right=helper(in,post,rootin+1,inEnd,postStart+leftsize,postEnd-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {mp[inorder[i]]=i;}
        // unique
        return helper(inorder,postorder,0,inorder.size()-1,0,inorder.size()-1,mp);
    }
};