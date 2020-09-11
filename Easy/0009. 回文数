/**
* 题目见：https://leetcode-cn.com/problems/palindrome-number/
**/

/** 方案一：反转一半数字（性能好）**/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedNum = 0;
        while(reversedNum < x){                 // 只会反转一半
            reversedNum = reversedNum * 10 + x % 10;
            x /= 10;
        }
        return (reversedNum == x) || (reversedNum / 10 == x);
    }
};


/** 方案二：转化成string直接比较（性能差） **/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string str;
        while(x > 0){
            int tmp = x % 10;
            x /= 10;
            str += to_string(tmp);
        }
        if(str.size() % 2){                     // 位数为奇
            int left = str.size() / 2, right = left;
            for(; left >= 0; left--, right++){
                if(str[left] != str[right]) return false;
            }
        }
        else{                                   // 位数为偶
            int left = str.size() / 2 - 1, right = left + 1;
            for(; left >= 0; left--, right++){
                if(str[left] != str[right]) return false;
            }
        }
        return true;
    }
};
