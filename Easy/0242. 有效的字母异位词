/**
* 题目见：https://leetcode-cn.com/problems/valid-anagram/
**/

/** 方法一（最快）：利用数组进行哈希表操作（最多26个小写字母）， 时间复杂度O(n)，空间复杂度O(1)**/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> arr1(26), arr2(26);                 // 所有vector里的元素被初始化为0
        
        for(int i = 0; i < s.size(); i++){
            arr1[(int)(s[i] - 'a')]++;
            arr2[(int)(t[i] - 'a')]++;
        }
        for(int i = 0; i < 26; i++)
            if(arr1[i] != arr2[i]) return false;
        return true;
    }
};

/** 方法二：哈希表（unordered_map），时间复杂度O(n)，空间复杂度O(k) **/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for(int i = 0; i < n; i++){
            if(map1.find(s[i]) == map1.end())
                map1[s[i]] = 1;
            else
                map1[s[i]]++;
            if(map2.find(t[i]) == map2.end())
                map2[t[i]] = 1;
            else  
                map2[t[i]]++;
        }

        auto iter = map1.begin();
        while(iter != map1.end()){
            if(map2.find(iter->first) == map2.end() || map2[iter->first] != iter->second)
                return false;
            iter++;
        }
        return true;
    }
};

/** 方法三：使用sort（）函数，时间复杂度O(nlogn)，空间复杂度O(n) **/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        vector<int> str1(n), str2(n);
        for(int i = 0; i < n; i++){
            str1[i] = (int)s[i];
            str2[i] = (int)t[i];
        }
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        for(int i = 0; i < n; i++){
            if(str1[i] != str2[i]) return false;
        }
        return true;
    }
};
