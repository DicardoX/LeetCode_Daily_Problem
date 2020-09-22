/**
* 题目见：https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
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

/** 方法：递归法中序遍历，时间68ms，69.49%，空间32.6MB，51.25% **/

class Solution {
private:
    int sum;
public:
    Solution(){sum = 0;}
    void postOrderTranversal(TreeNode* node) {
        int value = node->val;
        if(node->right) postOrderTranversal(node->right);
        value += sum;
        node->val = value;
        sum = value;
        if(node->left) postOrderTranversal(node->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return root;
        postOrderTranversal(root);
        return root;
    }
};
