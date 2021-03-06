/**
* 题目见：https://leetcode-cn.com/problems/word-search/submissions/
**/

/** 方法一：深度优先搜索（优化速度最快） **/

class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& isVisited, string& word, int row, int line, int step) {
        if(step == word.size()) return true;
        if(row < 0 || row >= board.size() || line < 0 || line >= board[0].size() || board[row][line] != word[step]) 
            return false;

        if(!isVisited[row][line]){
            isVisited[row][line] = true;
            if(check(board, isVisited, word, row + 1, line, step + 1) 
            || check(board, isVisited, word, row - 1, line, step + 1) 
            || check(board, isVisited, word, row, line + 1, step + 1) 
            || check(board, isVisited, word, row, line - 1, step + 1)){
            return true;
            }
            isVisited[row][line] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rowSize = board.size(), lineSize = board[0].size();
        vector<vector<int>> isVisited(rowSize, vector<int>(lineSize, 0));

        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < lineSize; j++){
                if(check(board, isVisited, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};


/** 方法二：深度优先搜索（优化，代码简洁，标准答案），复杂度相同，时间39.52%，空间40.09% **/

class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& isVisited, string& word, int row, int line, int step) {
        if(board[row][line] != word[step]) return false;
        else if(step == word.size() - 1) return true;
        isVisited[row][line] = true;

        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};                        // 利用数对代表四个方向
        bool result = false;
        for(const auto& dir : directions){
            int newRow = row + dir.first, newLine = line + dir.second;
            if(newRow >= 0 && newRow < board.size() && newLine >= 0 && newLine < board[0].size()){
                if(!isVisited[newRow][newLine]){
                    if(check(board, isVisited, word, newRow, newLine, step + 1)){
                        result = true;
                        break;
                    }
                }
            }
        }
        isVisited[row][line] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rowSize = board.size(), lineSize = board[0].size();
        vector<vector<int>> isVisited(rowSize, vector<int>(lineSize));

        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < lineSize; j++){
                if(check(board, isVisited, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};

/** 方法三：深度优先搜索（无优化），时间复杂度O(mn*3^L)（非常松的上界），空间复杂度O(mn)，时间5.02%，空间5.01% **/

class Solution {  
private:
    bool existed;
    int rowSize, lineSize;
public:
    Solution(){existed = false;}
    void DFS(vector<vector<char>>& board, vector<vector<int>> isVisited, string word, int row, int line, int step) {
        if(existed) return;                         // 若存在，返回
        if(step == word.size()){                    // 找到答案，存在
            existed = true;
            return;
        }
        if(row + 1 < rowSize && word[step] == board[row + 1][line] && !isVisited[row + 1][line]){
            isVisited[row + 1][line] = 1;
            DFS(board, isVisited, word, row + 1, line, step + 1);
            isVisited[row + 1][line] = 0;
        }
        if(row - 1 >= 0 && word[step] == board[row - 1][line] && !isVisited[row - 1][line]){
            isVisited[row - 1][line] = 1;
            DFS(board, isVisited, word, row - 1, line, step + 1);
            isVisited[row - 1][line] = 0;
        }
        if(line + 1 < lineSize && word[step] == board[row][line + 1] && !isVisited[row][line + 1]){
            isVisited[row][line + 1] = 1;
            DFS(board, isVisited, word, row, line + 1, step + 1);
            isVisited[row][line + 1] = 0;
        }
        if(line - 1 >= 0 && word[step] == board[row][line - 1] && !isVisited[row][line - 1]){
            isVisited[row][line - 1] = 1;
            DFS(board, isVisited, word, row, line - 1, step + 1);
            isVisited[row][line - 1] = 0;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        rowSize = board.size(), lineSize = board[0].size();
        vector<vector<int>> isVisited(rowSize, vector<int> (lineSize, 0));

        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < lineSize; j++){
                if(board[i][j] != word[0]) continue;
                isVisited[i][j] = 1;
                DFS(board, isVisited, word, i, j, 1);
                isVisited[i][j] = 0;
            }
        }
        return existed;
    }
};
