/**
* 题目见：https://leetcode-cn.com/problems/permutation-sequence/
**/

/** 方法一：数学+缩小问题规模 **/

class Solution {
public:
    void numShift(int shift[], int elm, int n){
        for(int i = elm; i < n - 1; i++) 
            shift[i] = shift[i + 1];
    }

    string getPermutation(int n, int k) {
        int res[n];                         // 存储结果
        int shift[n];                       // 剩余数组移位，如1，2，3在2被选择之后变为1，3，x
        string str;

        vector<int> factorial(n);
        factorial[0] = 1;
        shift[0] = 1;
        for(int i = 1; i < n; i++){
            factorial[i] = factorial[i - 1] * i;
            shift[i] = i + 1;
        }
        int index = 0;
        k--;                                // 保证共移动k-1次
        while(index < n){
            int elm = k / factorial[n - 1 - index];
            k %= factorial[n - 1 - index];
            res[index++] = shift[elm];
            numShift(shift, elm, n);
        }

        for(int i = 0; i < n; i++) str += to_string(res[i]);

        return str;
    }
};

/** 方法二：暴力穷举法（利用next_permutation()函数） **/

class Solution {
public:
    string getPermutation(int n, int k) {
        int arr[n];
        string str;
        for(int i = 0; i < n; i++) arr[i] = i + 1;

        while(--k) next_permutation(arr, arr+n);
        for(int i = 0; i < n; i++) 
            str += to_string(arr[i]);
        return str;
    }
};
