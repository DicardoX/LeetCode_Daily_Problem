// Link: https://leetcode-cn.com/problems/container-with-most-water/

// Solution: 双指针法。设置左右两个指针，每次向内移动较矮的那个idx（原因是短板效应）。

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left_idx = 0, right_idx = height.size() - 1;
        int max_area = 0;

        while(left_idx < right_idx) {
            int tmp_area = (right_idx - left_idx) * min(height[left_idx], height[right_idx]);
            max_area = max(max_area, tmp_area);
            if(height[left_idx] <= height[right_idx]) {
                left_idx++;
            } else {
                right_idx--;
            }
        }
        return max_area;
    }
};