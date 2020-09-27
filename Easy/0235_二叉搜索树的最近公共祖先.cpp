/**
* 题目见：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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

/** 方法：递归搜索，注意不同情况下递归函数返回值的判别，以及终止条件的判断 **/

class Solution {
private:
    bool finished;
    TreeNode* ret;
public:
    Solution(){finished = false; ret = new TreeNode(-1);}
    bool search(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(finished) return false;
        bool found_one = false;
        if(node->val == p->val || node->val == q->val) {    // 如果当前结点是目标值中的一个
            found_one = true;
        }      
        bool lflag = false, rflag = false;
        if(node->left) lflag = search(node->left, p, q);    // 搜索左子树
        if(node->right) rflag = search(node->right, p, q);  // 搜索右子树
        // 若：（1）目标值分别位于左右子树；（2）左右子树中的一棵含一个目标值，另一个是当前结点；则记录当前结点为二叉搜索树的最近公共祖先，同时标记finished为true，返回false
        if((lflag && rflag) || ((lflag || rflag) && found_one)) {   
            finished = true;
            ret->val = node->val;
            return false;
        }
        // 若：（1）仅在左右子树中找到一个目标值；（2）仅当前结点为其中一个目标值；则返回true
        if(((lflag || rflag) && !found_one) || found_one) return true;
        // 若在左右子树及当前结点中都未找到目标值，则返回false
        return false;
    } 

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q) return NULL;
        search(root, p, q);
        return ret;
    }
};
