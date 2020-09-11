/**
* 题目见：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
**/


/** 基于原始版本的优化版本，使用扫描+哈希集合，时间复杂度O(n)，空间复杂度O(m) **/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> strMap;
        int index = 0, begin = 0;
        int maxLen = 0;

        while(index < s.size()){
            while(strMap.find(s[index]) == strMap.end()){        // 不从重复字符的下一位开始，直接从原先位置往下统计，省去了保留部分的重复统计
                strMap[s[index]] = index;
                index++;
                if(index >= s.size()) break;
            }

            int tmpBegin = begin;
            begin = strMap[s[index]] + 1;
            for(int i = tmpBegin; i < begin; i++){              // 仅清空无用的部分                    
                strMap.erase(s[i]);
            }
            int tmpLen = index - tmpBegin;
            maxLen = (tmpLen > maxLen) ? tmpLen : maxLen;
        }
        return maxLen;
    }
};

/** 原始版本，使用优化遍历+哈希，时间复杂度O(n^3), 空间复杂度O(m)**/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> strMap;
        int index = 0, begin = 0;
        int maxLen = 0, tmpLen;

        while(index < s.length()){
            tmpLen = 0;
            index = begin;
            while(strMap.find(s[index]) == strMap.end()){
                tmpLen++;
                strMap[s[index]] = index;
                index++;
                if(index >= s.length()) break;
            }

            int tmpBegin = begin;
            begin = strMap[s[index]] + 1;
            for(int i = tmpBegin; i < index; i++){                                  // 每次刷新哈希表，时间长
                strMap.erase(s[i]);
            }
            maxLen = (tmpLen > maxLen) ? tmpLen : maxLen;
        }
        return maxLen;
    }
};


/** 官方答案，枚举左节点，窗口扫描，不够好 **/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> strMap;
        int rindex = -1;
        int res = 0;

        for(int i = 0; i < s.size(); i++){                                      // 枚举起始点
            if(i) strMap.erase(s[i-1]);                                         // 左节点右移一位
            while(rindex + 1 < s.size() && !strMap.count(s[rindex + 1]))        // 尽可能向右移动终止点
                strMap.insert(s[++rindex]);
            res = max(res, rindex - i + 1);
        }
        return res;
    }
};




