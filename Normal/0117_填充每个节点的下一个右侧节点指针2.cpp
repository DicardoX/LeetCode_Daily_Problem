/**
* 题目见：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/
**/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/** 方法：层次遍历 **/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> myQueue;

        myQueue.push(root);                 // 将根节点放入队列
        root->next = NULL;
        while(!myQueue.empty()) {
            int queueSize = myQueue.size() - 1;         // 获取当前层的节点数 - 1
            Node* prevNode = myQueue.front();           // 获取当前层的第一个节点
            if(prevNode->left) myQueue.push(prevNode->left);            // 若该节点有左孩子，入队
            if(prevNode->right) myQueue.push(prevNode->right);          // 若该节点有右孩子，入队
            myQueue.pop();                              // 将该节点出队

            for(int i = 0; i < queueSize; i++) {            // 依次遍历该层节点
                Node* curNode = myQueue.front();
                myQueue.pop();
                if(curNode->left) myQueue.push(curNode->left);
                if(curNode->right) myQueue.push(curNode->right);
                prevNode->next = curNode;                   // 将前一个节点的next指针指到当前节点
                prevNode = curNode;                         // 更新prevNode
            }
        }
        return root;
    }
};
