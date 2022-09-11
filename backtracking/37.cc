#include "../defs.h"

class Solution
{
private:
    bool isValid(vector<vector<char>> &board, int row, int col, char value)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == value)
            {
                return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == value)
            {
                return false;
            }
        }
        //向三取整，学到了
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++)
        {
            for (int j = startCol; j < startCol + 3; j++)
            {
                if (board[i][j] == value)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool backtracking(vector<vector<char>> &board, int startRow)
    {

        for (int i = startRow; i < 9; i++)
        {
            for (int j = 0;j<9; j++)
            {
                if(board[i][j]!='.') continue;
                for (char k = '1'; k <= '9'; k++)
                {
                    if(isValid(board,i,j,k)){
                        board[i][j]=k;
                        if(backtracking(board,i)) return true;
                        board[i][j]='.';
                    }
                }
                return false;
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board, 0);
    }
};