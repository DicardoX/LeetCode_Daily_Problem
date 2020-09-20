/**
* 题目见：https://leetcode-cn.com/problems/subsets/
**/

/** 方案：回溯（时间复杂度O(n * 2^n)， 击败60.29%，空间击败5.98% **/

class Solution {
public:
    void search(vector<vector<int>>& ret, vector<int>& combination, vector<int>& nums, int step) {
        if(step == nums.size()) {
            ret.emplace_back(combination);                  // O(n)
            return;
        }
        search(ret, combination, nums, step + 1);           // Not chosen
        combination.emplace_back(nums[step]);
        search(ret, combination, nums, step + 1);           // Chosen
        combination.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> combination;
        search(ret, combination, nums, 0);
        return ret;
    }
};
