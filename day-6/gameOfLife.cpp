class Solution
{
    int count(int i, int j, vector<vector<int>> &board)
    {
        if (i == -1 || j == -1 || i == board.size() || j == board[0].size() || board[i][j] == 0)
        {
            return 0;
        }

        return 1;
    }

public:
    void gameOfLife(vector<vector<int>> &board)
    {

        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> ans(rows, vector<int>(cols));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int sum = count(i - 1, j - 1, board) + count(i - 1, j, board) + count(i - 1, j + 1, board) + count(i, j + 1, board) + count(i + 1, j + 1, board) + count(i + 1, j, board) + count(i + 1, j - 1, board) + count(i, j - 1, board);

                if (board[i][j] == 0)
                {
                    if (sum == 3)
                        ans[i][j] = 1;
                    else
                        ans[i][j] = 0;
                }

                else if (board[i][j] == 1)
                {
                    if (sum < 2 || sum > 3)
                        ans[i][j] = 0;
                    else
                        ans[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                board[i][j] = ans[i][j];
            }
        }
    }
};