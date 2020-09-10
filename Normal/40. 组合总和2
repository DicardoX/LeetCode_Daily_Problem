/**
* 题目见：https://leetcode-cn.com/problems/combination-sum-ii/
**/

/** 自己的代码：BFS（回溯） **/

class Solution {
public:
    void BFS(vector<int>& candidates, vector<vector<int>>& res, vector<int> &num, int index, int target){
        if(target == 0){
            res.emplace_back(num);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            if(candidates[i] > target) return;
            if(i > index && candidates[i] == candidates[i - 1]) continue;           // 如果之前已经使用过相同元素往后递归了，则直接跳到下一个，这样就不会出翔两个[1, 7]了（如果输入为[10,1,2,7,6,1,5]）       
            num.emplace_back(candidates[i]);
            BFS(candidates, res, num, i + 1, target - candidates[i]);               // i+1 来访问下一个元素
            num.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(!candidates.size()) return res;
        sort(candidates.begin(), candidates.end());             // 按从小到大排序
        vector<int> num;
        BFS(candidates, res, num, 0, target);
        return res;
    }
};

/** 别人的代码 **/

class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            DFS(i + 1, target - candidates[i]); // 元素不可重复利用，使用下一个即i+1
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);
        return res;
    }
};
