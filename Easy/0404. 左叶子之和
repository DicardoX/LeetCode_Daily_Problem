/**
* 题目见：https://leetcode-cn.com/problems/sum-of-left-leaves/
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

/** 方案：遍历 **/

class Solution {
private:
    int ret;
public:
    Solution(){ret = 0;}
    void search(TreeNode* node, int type) {             // 0 for left, 1 for right
        if(type == 0 && node->left == NULL && node->right == NULL) {
            ret += node -> val;
            return;
        }
        if(node->left) search(node->left, 0);
        if(node->right) search(node->right, 1);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return ret;
        search(root, 1);
        return ret;
    }
};
