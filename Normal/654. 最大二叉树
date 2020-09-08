/**
* 题目见：https://leetcode-cn.com/problems/maximum-binary-tree/
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

/** 方法：分治递归 + 使用迭代器 **/

class Solution {
public:
    TreeNode* treeBuild(vector<int>::iterator left, vector<int>::iterator right){
        if(left == right) return NULL;
        auto it = max_element(left, right);
        TreeNode* newNode = new TreeNode(*it);
        newNode->left = treeBuild(left, it);
        newNode->right = treeBuild(it + 1, right);
        return newNode;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return treeBuild(nums.begin(), nums.end());
    }
};
