/**
* 题目见：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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

/** 方法：从后序遍历找root，然后对中序进行递归分治 **/

class Solution {
public:
    TreeNode* construct(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr) {
        if(il == ir) return NULL;
        if(il == ir - 1) {
            TreeNode* tmpNode = new TreeNode(inorder[il]);
            return tmpNode;
        } 
        int root = postorder[pr - 1];
        int vis = 0;
        for(int i = il; i < ir; i++) 
            if(root == inorder[i]) {
                vis = i;
                break;
            }        
        
        TreeNode* node = new TreeNode(inorder[vis]);
        node->left = construct(inorder, postorder, il, vis, pl, pl + vis - il);
        node->right = construct(inorder, postorder, vis + 1, ir, pr - 1 - (ir - vis - 1), pr - 1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root;
        if(!inorder.size()) return root;
        root = construct(inorder, postorder, 0, inorder.size(), 0, postorder.size());
        return root;
    }
};

