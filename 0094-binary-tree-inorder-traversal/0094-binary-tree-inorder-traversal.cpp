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
    void inorder(TreeNode* root, vector<int> &res) {
        if(root==nullptr) return;
        inorder(root->left, res);        
        res.push_back(root->val);        
        inorder(root->right, res);        
    }

    vector<int> inorderTraversal(TreeNode* root) {
        // TreeNode* curr = root;
        // vector<int> res;
        // stack<TreeNode*> s;
        // while(curr!=nullptr || !s.empty()) {
        //     while(curr!=nullptr) {
        //         s.push(curr);
        //         curr = curr->left;
        //     }
        //     curr = s.top();
        //     s.pop();
        //     res.push_back(curr->val);
        //     curr = curr->right;
        // }

        vector<int> res;
        inorder(root, res);

        return res;
    }
};