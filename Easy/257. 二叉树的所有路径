/**
* 题目见：https://leetcode-cn.com/problems/binary-tree-paths/
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
class Solution {
public:
    void routineFound(TreeNode* node, vector<string>& res, string path){
        path += to_string(node->val);

        if(node->left == NULL && node->right == NULL){
            res.push_back(path);
            return;
        }

        if(node->left) routineFound(node->left, res, path + "->");
        if(node->right) routineFound(node->right, res, path + "->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string stk;
        if(root == NULL) return res;
        routineFound(root, res, stk);

        return res;
    }
};

