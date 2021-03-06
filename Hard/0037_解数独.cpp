/**
* 题目见：https://leetcode-cn.com/problems/sudoku-solver/
**/

/** 方法：递归回溯，可以考虑使用bitset来压缩优化空间，具体代码见题解 **/

class Solution {
private:
    bool lineStatus[9][9];                          // lineStatus[line][num]表示num+1已经在第line+1行出现过
    bool columnStatus[9][9];                        // columnStatus[num][col]表示num+1已经在第col+1列出现过
    bool blockStatus[3][3][9];                      // block[i][j][num]表示num+1已经在第i+1行第j+1列的块中出现过
    vector<pair<int, int>> restSpace;               // 记录空闲位置
    bool finished;
public:
    Solution(){finished = false;}
    void DFS(vector<vector<char>>& board, int step) {
        if(finished) return;
        if(step == restSpace.size()) {
            finished = true;
            return;
        }

        auto [i, j] = restSpace[step];
        for(int num = 0; num < 9 && !finished; num++) {                 // 注意：!finished不能去掉，否则可能会在最后一次发生意外的修改
            if(!lineStatus[i][num] && !columnStatus[num][j] && !blockStatus[i / 3][j / 3][num]) {
                lineStatus[i][num] = columnStatus[num][j] = blockStatus[i / 3][j / 3][num] = true;
                board[i][j] = num + '0' + 1;
                DFS(board, step + 1);
                lineStatus[i][num] = columnStatus[num][j] = blockStatus[i / 3][j / 3][num] = false;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(lineStatus, false, sizeof(lineStatus));
        memset(columnStatus, false, sizeof(columnStatus));
        memset(blockStatus, false, sizeof(blockStatus));

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int tmpNum = board[i][j] - '0';
                    lineStatus[i][tmpNum - 1] = true;
                    columnStatus[tmpNum - 1][j] = true;
                    blockStatus[i / 3][j / 3][tmpNum - 1] = true;
                } else{
                    restSpace.emplace_back(i, j);
                }
            }
        }
        DFS(board, 0);
    }
};
