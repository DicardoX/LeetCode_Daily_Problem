/**
* 题目见：https://leetcode-cn.com/problems/longest-common-prefix/
**/

/** 方法：顺序遍历 **/

class Solution {
public:
    void compare(string& str, string& part) {
        int vis = -1;
        for(int i = 0; i < part.size() && i < str.size(); i++) {
            if(str[i] != part[i]) {
                vis = i - 1;
                break;
            } else if(i == part.size() - 1 || i == str.size() - 1) {
                vis = i;
                break;
            }
        }

        while(part.size() > vis + 1) part.pop_back();
    }

    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        if(!strs.size()) return ret;
        if(strs.size() == 1) return strs[0]; 
        string str1 = strs[0], str2 = strs[1];
        int vis = 0;
        while(vis < str1.size() && vis < str2.size() && str1[vis] == str2[vis]) {
            ret = ret + str1[vis++];
        }
        for(int i = 2; i < strs.size(); i++) {
            compare(strs[i], ret);
        }
        return ret;
    }
};
