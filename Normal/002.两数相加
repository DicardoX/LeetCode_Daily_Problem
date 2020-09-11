/** 
* 题目见：https://leetcode-cn.com/problems/add-two-numbers/
**/


/** 高阶代码（代码简单，但时间、空间消耗大） **/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0), *p = &head;
        int flag = 0;
        int tmpRes;

        while(l1 || l2 || flag)
        {
            tmpRes = 0;
            if(l1 != NULL) tmpRes += l1->val;
            if(l2 != NULL) tmpRes += l2->val;
            tmpRes += flag;

            flag = tmpRes / 10;
            tmpRes %= 10;

            ListNode *nextNode = new ListNode(tmpRes);
            nextNode->next = NULL;
            
            p->next = nextNode;
            p = p->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL; 
        }

        return head.next;
    }
};


/** 原始代码（代码冗长，但时间、空间复杂度小） **/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int flag = 0;
        int tmpRes;

        /** 并行情况 **/
        while(p1->next != NULL && p2->next != NULL)
        {
            tmpRes = p1->val + p2->val + flag;
            p1->val = tmpRes % 10;
            flag = tmpRes / 10;
            p1 = p1->next;
            p2 = p2->next;
        }

        /** 处理并行情况的最后一个元素 **/
        tmpRes = p1->val + p2->val + flag;
        p1->val = tmpRes % 10;
        flag = tmpRes / 10;   

        /** 若l1没有结束 **/
        while(p1->next != NULL){
            if(!flag) break;
            p1 = p1->next;
            tmpRes = p1->val + flag;
            p1->val = tmpRes % 10;
            flag = tmpRes / 10;
        }

        /** 若l2没有结束 **/
        while(p2->next != NULL){
            p2 = p2->next;
            tmpRes = p2->val + flag;
            p1->next = new ListNode(tmpRes % 10);
            flag = tmpRes / 10;
            p1 = p1->next;
            p1->next = NULL;  
        }

        /** 处理最后一位可能的进位情况 **/
        if(p2->next == NULL && p1->next == NULL && flag){
            p1->next = new ListNode(1);
            p1 = p1->next;
            p1->next = NULL;
        }
           
        return l1;
    }
};


