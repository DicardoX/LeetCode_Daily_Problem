/**
* 题目见：https://leetcode-cn.com/problems/invert-binary-tree/
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/** 方法：递归 **/

class Solution {
public:
    void func(TreeNode* node) {
        if(node->left && node->right) {
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
        }
        else if (!node->left && node->right) {
            node->left = node->right;
            node->right = NULL;
        }
        else if(node->left && !node->right) {
            node->right = node->left;
            node->left = NULL;
        }
        if(node->left) func(node->left);
        if(node->right) func(node->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        func(root);
        return root;
    }
};
