/**
* 题目见：https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/
**/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/** 方法一：递归（简单） **/

class Solution {
public:
    void treeSearch(Node* node, vector<int>& res){
        int size = node->children.size();
        for(int i = 0; i < size; i++){
            res.push_back(node->children[i]->val);
            treeSearch(node->children[i], res);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == NULL) return res; 
        res.push_back(root->val);
        treeSearch(root, res);
        return res;
    }
};
