/**
* 题目见：https://leetcode-cn.com/problems/top-k-frequent-elements/
**/

/** 方法一：直接调用pythonic函数（python语言） **/ 

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """

        return [num for num, _ in Counter(nums).most_common(k)]
        
/** 方法二：哈希表构建出现次数数组 + 最小堆（优先级队列）排序 **/

class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n){
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for(auto& v : nums){                        // 基于哈希表构建出现次数数组的简洁表达
            occurrences[v]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);           // 优先级队列作为最小堆
        for(auto& [num, count] : occurrences){
            if(q.size() == k){
                if(q.top().second < count){
                    q.pop();
                    q.emplace(num, count);              // emplace()函数：原地构造一个元素并插入队列
                }
            }
            else{
                q.emplace(num, count);
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.emplace_back(q.top().first);            // emplace_back()比push_back()快一倍
            q.pop();
        }
        return res;        
    }
};
