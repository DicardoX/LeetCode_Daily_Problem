# 题目见：https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/

class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        matrix = [0] * 100
        ret = 0

        for x, y in dominoes:
            index = (x * 10 + y if x <= y else y * 10 + x)
            ret += matrix[index]
            matrix[index] += 1
        return ret
