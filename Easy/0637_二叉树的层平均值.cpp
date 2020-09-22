/**
* 题目见：https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
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

/** 方法：层次遍历 **/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root == NULL) return res;
        queue<TreeNode*> myQueue;

        myQueue.push(root);
        while(!myQueue.empty()){
            double tmpSum = 0;
            int size = myQueue.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = myQueue.front();
                tmpSum += node->val;
                myQueue.pop();
                if(node->left) myQueue.push(node->left);
                if(node->right) myQueue.push(node->right);
            }
            res.emplace_back((double)(tmpSum / size));
        }
        return res;
    }
};
