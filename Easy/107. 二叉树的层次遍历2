/**
* 题目见：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
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

/** 方法：利用队列进行层次遍历，最后reverse **/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> myQueue;                   // 进行层次遍历的队列

        myQueue.push(root);
        while(myQueue.size()){
            int n = myQueue.size();
            vector<int> tmp;
            for(int i = 0; i < n; i++){             // for循环比while(n--)要快
                TreeNode* node = myQueue.front();
                myQueue.pop();
                if(node->left) myQueue.push(node->left);
                if(node->right) myQueue.push(node->right);
                tmp.push_back(node->val);
            }
            res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
