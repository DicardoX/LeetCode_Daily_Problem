/**
* 题目见：https://leetcode-cn.com/problems/combinations/
**/

/** 方法一：DFS + 剪枝，时间复杂度O((n, k) * k) **/

class Solution {
private:
    vector<vector<int>> res;
    vector<int> combination;
public:
    void DFS(vector<int>& combination, int num, int depth, int k, int n){
        if(combination.size() + n - num + 1 < k) return;                // 剪枝
        combination.emplace_back(num);
        if(depth == k){
            res.emplace_back(combination);      
        } else{
            for(int i = num + 1; i <= n; i++)
                DFS(combination, i, depth + 1, k, n);
        }
        combination.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        for(int i = 1; i <= n; i++)
            DFS(combination, i, 1, k, n);
        return res;
    }
};
