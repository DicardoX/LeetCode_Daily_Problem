// Link: https://leetcode-cn.com/problems/3sum/

// Solution: 三指针法。排序后顺序遍历非重复的item1，并在后面的子区间内使用双指针法，注意特殊情况的判别，以及满足条件后的自发改变。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        // 为了判断如[0, 0, 0, 0]的特殊情况，必须左右两个指针的值不同时与上一对值相等才可以算入ret
        int prev_left = 1e6;
        int prev_right = 1e6;

        // Empty
        if(nums.size() < 3) {
            return {};
        }
        // Sort
        sort(nums.begin(), nums.end());

        for(auto itr_1 = nums.begin(); itr_1 < nums.end() - 2; itr_1++) {
            // Skip the same header
            if(itr_1 > nums.begin() && *itr_1 == *(itr_1-1)) {
                continue;
            }
            // 转化为两数之和，双指针法
            auto itr_2 = itr_1 + 1, itr_3 = nums.end() - 1;
            while(itr_2 < itr_3) {
                if(*itr_1 + *itr_2 + *itr_3 == 0 && (*itr_2 != prev_left || *itr_3 != prev_right)) {
                    vector<int> tmp_ans = {*itr_1, *itr_2, *itr_3};
                    ret.push_back(tmp_ans);
                    prev_left = *itr_2;
                    prev_right = *itr_3;
                    // Change, or will infinitely loop
                    itr_2++;
                }
                else if(*itr_1 + *itr_2 + *itr_3 < 0) {
                    itr_2++;
                }
                else {
                    itr_3--;
                }
            }
        }

        return ret;
    }
};