/**
* https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/
**/

/** 方法：递归法中序遍历，时间0ms，100%，空间8MB，78.08%，与538题相同 **/

class Solution {
private:
    int sum;
public:
    Solution(){sum = 0;}
    void postOrderTranversal(TreeNode* node) {
        int value = node->val;
        if(node->right) postOrderTranversal(node->right);
        value += sum;
        node->val = value;
        sum = value;
        if(node->left) postOrderTranversal(node->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return root;
        postOrderTranversal(root);
        return root;
    }
};
