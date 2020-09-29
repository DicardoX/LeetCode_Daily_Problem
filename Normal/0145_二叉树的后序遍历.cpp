/**
* 题目见：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
**/

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
 
 /** 方法一：递归 **/
 
 class Solution {
public:
    void func(vector<int>& ret, TreeNode* node) {
        if(node->left) func(ret, node->left);
        if(node->right) func(ret, node->right);
        ret.emplace_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        func(ret, root);
        return ret;
    }
};

/** 方法二：迭代 **/




