/**
* 题目见：https://leetcode-cn.com/problems/path-sum-ii/
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

/** 方法：遍历二叉树，注意会出现负值结点，谨慎选择终止条件 **/

class Solution {
public:
    void search(vector<vector<int>>& ret, vector<int>& path, TreeNode* node, int tmpSum, int sum) {
        tmpSum += node->val;
        path.emplace_back(node->val);
        
        if(tmpSum == sum && !node->left && !node->right) {
            ret.emplace_back(path);
            path.pop_back();
            return;
        }
        if(node->left) search(ret, path, node->left, tmpSum, sum);
        if(node->right) search(ret, path, node->right, tmpSum, sum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if(root == NULL) return ret;
        vector<int> path;
        search(ret, path, root, 0, sum);
        return ret;
    }
};
