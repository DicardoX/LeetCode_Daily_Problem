/**
*  题目：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
**/

class Solution {
public:
    void swap(char &a, char &b){
        char tmp = a;
        a = b;
        b = tmp;
    }

    string reverseWords(string s) {
        if(s == ""){
            return s;
        }

        int begin = 0, end, len = s.length();
        for(int i = 0; i < len+1; i++)
        {
            if(s[i] == ' ' || s[i] == '\0'){
                for(end = i-1; begin < end; begin++, end--){
                    swap(s[begin], s[end]);
                }
                begin = i+1;
            }
        }

        return s;
    }
};
