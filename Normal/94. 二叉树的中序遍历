/**
* 题目见：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
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

/** 方法一：利用栈模拟递归 **/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> myStack;

        TreeNode* cur = root;
        while(cur != NULL || !myStack.empty()){
            while(cur != NULL){
                myStack.push(cur);
                cur = cur->left;
            }
            cur = myStack.top();
            myStack.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};

/** 方法二：递归 **/

class Solution {
public:
    void treeSearch(TreeNode* node, vector<int>& res){
        if(node->left) treeSearch(node->left, res);
        res.push_back(node->val);
        if(node->right) treeSearch(node->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        treeSearch(root, res);
        return res;
    }
};

