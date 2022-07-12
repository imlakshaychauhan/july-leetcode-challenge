// https://leetcode.com/problems/binary-tree-right-side-view/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size(), level;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                level = node->val;
            }
            ans.push_back(level);
        }
        return ans;
    }
};