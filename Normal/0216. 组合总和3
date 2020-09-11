/**
* 题目见：https://leetcode-cn.com/problems/combination-sum-iii/submissions/
**/

/** 方法一：二进制位运算（时间45.65%，空间99.79%） **/

class Solution {
private:
    inline int sumUp(int num) {
        int res = 0; 
        for(int i = 1; i <= num; i++) res += i;
        return res;
    }
    bool check(vector<int>& path, int mask, int k, int n) {
        path.clear();
        for(int i = 0; i < 9; i++){
            if((1 << i) & mask)                     // 若mask对应的位为1
                path.emplace_back(i + 1);
        }
        return (path.size() == k) && (accumulate(path.begin(), path.end(), 0) == n);
    }
public: 
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(k <= 0 || k > 9 || n < sumUp(k) || n > sumUp(9)) return res;
        vector<int> path;
        
        for(int mask = 0; mask < (1 << 9); mask++)
            if(check(path, mask, k, n)) res.emplace_back(path);
        
        return res;
    }
};

/** 方法二：BFS递归回溯（组合枚举）(时间45.65%，空间42.77%) **/

class Solution {
private:
    int sumUp(int num){
        int res = 0;
        for(int i = 1; i <= num; i++) res += i;
        return res;
    }
public:
    void BFS(vector<vector<int>>& res, vector<int>& path, int k, int n, int index) {
        if(n == 0 && path.size() == k){     
            res.emplace_back(path);
            return;
        }
        if((n == 0 && path.size() != k) || (n != 0 && path.size() == k) || index > n) return;        // 不满足条件

        for(int i = index; i <= 9 && n >= i; i++){                                      // 注意是 n >= i是继续循环
            path.emplace_back(i);
            BFS(res, path, k, n - i, i + 1);                                            // 不能重复选自己
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(k <= 0 || k > 9 || n < sumUp(k) || n > sumUp(9)) return res;
        vector<int> path;
        BFS(res, path, k, n, 1);
        return res;
    }
};
