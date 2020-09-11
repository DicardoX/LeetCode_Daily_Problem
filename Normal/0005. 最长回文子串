/**
* 题目见：https://leetcode-cn.com/problems/longest-palindromic-substring/
**/

/** 方案一：动态规划，时间复杂度O(n^2), 空间复杂度O(n^2)，实际性能表现较差 **/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(!n) return "";
        vector<vector<int>> DP(n, vector<int>(n));
        int beginVis = 0, length = 1;

        for(int i = 0; i < n-1; i++){
            DP[i][i] = 1;
            if(s[i] == s[i+1]){
                DP[i][i+1] = 1;
                beginVis = i; length = 2;
            }
            else{
                DP[i][i+1] = 0;   
            }  
        }
        DP[n-1][n-1] = 1;

        for(int len = 3; len <= n; len++){
            for(int begin = 0; begin < n - len + 1; begin++){
                DP[begin][begin + len - 1] = DP[begin + 1][begin + len - 2] && (s[begin] == s[begin + len - 1]);
                if(DP[begin][begin + len - 1] && length < len){
                    beginVis = begin; length = len;
                }
            }
        }

        return s.substr(beginVis, length);
    }
};

/** 方案二：中心扩散法，先找长度为1或2的回文中心，再向左右扩展，时间复杂度O(n^2)，空间复杂度O(1)，实际性能表现较好 **/

class Solution {
public:
    pair<int, int> rangeExpanse(const string& s, int left, int right){                          // 回文串扩展函数
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--; right++;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int begin = 0, len = 0;

        for(int i = 0; i < s.size(); i++){
            auto [l1, r1] = rangeExpanse(s, i, i);
            auto [l2, r2] = rangeExpanse(s, i, i + 1);

            if(r1 - l1 + 1 > len){
                begin = l1;
                len = r1 - l1 + 1;
            }
            if(r2 - l2 + 1 > len){
                begin = l2;
                len = r2 - l2 + 1;
            }
        }
        return s.substr(begin, len);
    }
};

