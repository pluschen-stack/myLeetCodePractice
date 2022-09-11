#include "../defs.h"

class Solution
{
private:
    vector<vector<string>> ans;

    vector<bool> path;
    void backtracking(int n, vector<string> &chessBoard, int alreadyPlacedNum)
    {
        if (alreadyPlacedNum == n)
        {
            ans.push_back(chessBoard);
            return;
        }
        for (int i = 0; i < n; i++)
        {

            if (path[i] == true)
            {
                continue;
            }
            bool flag = true;
            for (int j = 1; j <= alreadyPlacedNum && j <= i; j++)
            {
                if (chessBoard[alreadyPlacedNum - j][i - j] == 'Q')
                {
                    flag = false;
                }
            }
            for (int j = 1; j <= alreadyPlacedNum && j < n - i; j++)
            {
                if (chessBoard[alreadyPlacedNum - j][i + j] == 'Q')
                {
                    flag = false;
                }
            }
            if (flag)
            {
                path[i] = true;
                chessBoard[alreadyPlacedNum][i] = 'Q';
                backtracking(n, chessBoard, alreadyPlacedNum + 1);
                chessBoard[alreadyPlacedNum][i] = '.';
                path[i] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        //N皇后原来是这样啊。了解回溯后，这道题就只麻烦在处理同一列和同一斜线了。
        path.clear();
        path.resize(n);
        vector<string> chessBoard(n, string(n, '.'));
        for (int i = 0; i < path.size(); i++)
        {
            path[i] = false;
        }
        ans.clear();
        backtracking(n, chessBoard, 0);
        return ans;
    }
};

int main()
{
    Solution s;
    s.solveNQueens(4);
}