/**
* 题目见：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
**/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> strList;
        if(digits.empty()){
            return strList;
        }

        unordered_map<char, string> keyBoard{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        string str;
        traceBack(keyBoard, digits, strList, str, 0);
        return strList;

    }

    void traceBack(const unordered_map<char, string> & keyBoard, const string & digits, vector<string> & strList, string & str, int index)
    {
        if(index == digits.length()){
            strList.push_back(str);
            return;
        }
        char digit = digits[index];
        const string & letters = keyBoard.at(digit);
        for(const char & letter : letters){
            str.push_back(letter);
            traceBack(keyBoard, digits, strList, str, index+1);
            str.pop_back();
        }

    }
};
