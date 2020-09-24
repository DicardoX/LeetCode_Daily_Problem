/**
* 题目见：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
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

/** 方法：中序遍历 **/

class Solution {
private:
    int maxNum;
public:
    Solution(){maxNum = 0;}
    void inOrderTraversal(vector<int>& list, TreeNode* node) {
        if(node->left) inOrderTraversal(list, node->left);
        list.emplace_back(node->val);
        if(node->right) inOrderTraversal(list, node->right);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ret;
        vector<int> list;
        if(root == NULL) return ret;

        inOrderTraversal(list, root);
        int maxNum = 1, tmpNum = 1;
        ret.emplace_back(list[0]);          // 先把首元素放入
        for(int i = 1; i < list.size(); i++) {      // 遍历全部元素
            if(list[i] == list[i-1]) {      // 若和前一个元素相等
                tmpNum++;
                if(maxNum <= tmpNum) {      
                    if(maxNum < tmpNum) {   // 若该元素个数大于max，清空vector并将该元素放入，更新max
                        ret.clear();
                        ret.emplace_back(list[i]);
                        maxNum = tmpNum;
                    } else {
                        ret.emplace_back(list[i]); // 若该元素个数等于max，将该元素放入
                    }
                }
            } else {                                // 若该元素和前一个元素不想等
                tmpNum = 1;                         // 当前元素个数为1
                if(maxNum == tmpNum) {              // 元素个数等于max，将该元素放入
                    ret.emplace_back(list[i]);
                }
            }
        }
        
        return ret;
    }
};
