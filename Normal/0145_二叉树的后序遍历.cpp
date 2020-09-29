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

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<TreeNode*> myStack1;        // myStack1用来第一次存储
        stack<TreeNode*> myStack2;        // myStack2用来第二次存储

        myStack1.push(root);
        while (!myStack1.empty() || !myStack2.empty()) {
            if(myStack1.empty()) {        // 若myStack1已经空，则将myStack2里的元素依次pop
                while(!myStack2.empty()) {
                    int topVal = myStack2.top()->val;
                    myStack2.pop();
                    ret.emplace_back(topVal);
                }
                break;
            }
            TreeNode* curNode = myStack1.top();     // 获取myStack1的栈顶元素，弹出
            myStack1.pop();
            if(curNode->left) myStack1.push(curNode->left);       // 先看左子树，因为在myStack2输出时会再次反序
            if(curNode->right) myStack1.push(curNode->right);     // 再看右子树
            myStack2.push(curNode);                 // 将当前节点push进myStack2
        }
        return ret;
    }
};


