/**
* 题目见：https://leetcode-cn.com/problems/binary-tree-cameras/
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

/** 方法：递归 **/

struct Status {
    int a, b, c;              
    // a：摄像头必须放在当前root时，覆盖整棵树需要的摄像头数目
    // b：覆盖整棵树所需要的摄像头数目
    // c：覆盖两棵子树所需要的摄像头数目，无论root是否有摄像头
};

class Solution {
public:
    Status DFS(TreeNode* node) {
        if(node == NULL) return {INT_MAX / 2, 0, 0};
        auto [la, lb, lc] = DFS(node->left);
        auto [ra, rb, rc] = DFS(node->right);
        int a = lc + rc + 1;
        int b = min(a, min(la + rb, lb + ra));
        int c = min(a, lb + rb); // 要么root放一个摄像头，要么左右子树分别保证自身全覆盖
        return {a, b, c};
    }

    int minCameraCover(TreeNode* root) {
        //if(root == NULL) return 0; 不需要
        auto [a, b, c] = DFS(root);
        return b;
    }
};
