/**
* 题目见：https://leetcode-cn.com/problems/balanced-binary-tree/
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
private:
    bool flag;
public:
    Solution(){flag = true;}
    int subtreeDepth(TreeNode* node){
        if(!flag) return -1;                // 若已经找到，则停止向下搜索
        if(node->right == NULL && node->left == NULL){                  // 叶子节点
            return 1;
        }
        int depth1 = 1, depth2 = 1;
        if(node->left) depth1 += subtreeDepth(node->left);
        if(node->right) depth2 += subtreeDepth(node->right);
        if(depth1 - depth2 > 1 || depth2 - depth1 > 1){
            flag = false;
            return -1;                    // 便于提高性能
        } 
        return max(depth1, depth2);
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        subtreeDepth(root);
        return flag;
    }
};
