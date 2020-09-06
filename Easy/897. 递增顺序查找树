/**
* 题目见：https://leetcode-cn.com/problems/increasing-order-search-tree/
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
 
 /** 方法一： 中序遍历 + 更改树的连接方式**/ 
 
 class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* resHead = new TreeNode(0);
        if(root == NULL) return NULL;
        stack<TreeNode*> myStack;

        TreeNode* cur = root;
        TreeNode* p = resHead;
        while(cur != NULL || !myStack.empty()){
            while(cur != NULL){
                myStack.push(cur);
                cur = cur->left;
            }
            TreeNode* node = myStack.top();
            myStack.pop();
            p->right = node;
            p->left = NULL;
            p = p->right;
            cur = node->right;
        }
        return resHead->right;
    }
};

/** 方法二：先找出中序，构造新的树 **/

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> order;
        TreeNode* resHead = new TreeNode(0);
        if(root == NULL) return NULL;
        stack<TreeNode*> myStack;

        TreeNode* cur = root;
        while(cur != NULL || !myStack.empty()){
            while(cur != NULL){
                myStack.push(cur);
                cur = cur->left;
            }
            cur = myStack.top();
            myStack.pop();
            order.push_back(cur->val);
            cur = cur->right;
        }

        TreeNode *p = resHead;
        for(int i = 0; i < order.size(); i++){
            p->right = new TreeNode(order[i]);
            p = p->right;
        }
        return resHead->right;
    }
};
