/**
* 题目见：https://leetcode-cn.com/problems/predict-the-winner/
**/

/** 方案一：递归 **/

class Solution {
public:
    // 1 for player 1, -1 for player 2
    int score(vector<int>& nums, int begin, int end, int turn){
        if(begin == end) return nums[begin] * turn;
        int score1 = score(nums, begin + 1, end, -turn) + nums[begin] * turn;
        int score2 = score(nums, begin, end - 1, -turn) + nums[end] * turn;
        return (turn == 1)? max(score1, score2) : min(score1, score2);
    }

    bool PredictTheWinner(vector<int>& nums) {
        return score(nums, 0, nums.size() - 1, 1) >= 0;
    }
};


/** 方案二：动态规划，优化空间 **/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        auto DP = vector<int>(n);                                           // 一维数组代替二维数组

        for(int i = 0; i < n; i++)
            DP[i] = nums[i];
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                DP[j] = max(nums[i] - DP[j], nums[j] - DP[j-1]);            // 状态转移方程
            }
        }
        return DP[n-1] >= 0;
    }

};

