/**
* 题目见：https://leetcode-cn.com/problems/list-of-depth-lcci/
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 

/** 方案：层次遍历 **/

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> res;
        if(tree == NULL) return res;
        queue<TreeNode*> myQueue;

        myQueue.push(tree);

        while(myQueue.size()){
            int n = myQueue.size();
            ListNode *newHead = new ListNode(0), *p = newHead;              // 注意头节点一定要申请空间！
            for(int i = 0; i < n; i++){
                TreeNode* node = myQueue.front();
                myQueue.pop();
                if(node->left) myQueue.push(node->left);
                if(node->right) myQueue.push(node->right);
                p->next = new ListNode(node->val);
                p = p->next;
            }
            res.push_back(newHead->next);
        }
        return res;      
    }
};
