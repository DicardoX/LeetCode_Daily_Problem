/**
* 题目见：https://leetcode-cn.com/problems/two-sum/solution/
**/

/** 方法一：遍历（O(n^2) in time, O(1) in space） **/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        bool flag = false;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        return res;
    }
};


/** 方法二：哈希表（O(n) in time, O(n) in space） **/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashMap;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(hashMap.find(nums[i]) == hashMap.end()){
                hashMap[target - nums[i]] = i;
            }
            else{
                res.push_back(i);
                res.push_back(hashMap[nums[i]]);
            }
        }
        return res;
    }
};
