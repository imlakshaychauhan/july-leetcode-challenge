// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
class Solution {
public:
    TreeNode* build(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie, map<int, int> &mp) {
        if(ps > pe || is > ie) return nullptr;
        TreeNode* root = new TreeNode(preorder[ps]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot - is;
        root->left = build(preorder, ps + 1, ps + numsLeft, inorder, is, inRoot - 1, mp);
        root->right = build(preorder, ps + numsLeft + 1, pe, inorder, inRoot + 1, ie, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    }
};