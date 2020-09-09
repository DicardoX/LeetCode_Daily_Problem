/**
* 题目见：https://leetcode-cn.com/problems/combination-sum/
**/

/** 方法一：广度优先搜索（搜索回溯） **/

class Solution {
public:
    void BFS(vector<int>& candidates, vector<vector<int>>& res, vector<int> &num, int index, int target){
        if(target == 0){
            res.emplace_back(num);
            return;
        }
        if(candidates[index] > target || index >= candidates.size()) return;
        
        for(int i = index; i < candidates.size(); i++){
            if(candidates[i] > target) return;
            num.emplace_back(candidates[i]);
            BFS(candidates, res, num, i, target - candidates[i]);
            num.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(!candidates.size()) return res;
        sort(candidates.begin(), candidates.end());             // 按从小到大排序
        vector<int> num;
        BFS(candidates, res, num, 0, target);
        return res;
    }
};
