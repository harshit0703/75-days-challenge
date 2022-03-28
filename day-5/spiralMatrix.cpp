class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> v;

        int firstrow = 0, lastrow = rows - 1;
        int firstcol = 0, lastcol = cols - 1;

        while (firstrow <= lastrow && firstcol <= lastcol)
        {

            // first row

            for (int i = firstcol; i <= lastcol; i++)
            {
                v.push_back(matrix[firstrow][i]);
            }
            firstrow++;

            // last col

            for (int i = firstrow; i <= lastrow; i++)
            {
                v.push_back(matrix[i][lastcol]);
            }
            lastcol--;

            // last row

            if (firstrow <= lastrow)
            {
                for (int i = lastcol; i >= firstcol; i--)
                {
                    v.push_back(matrix[lastrow][i]);
                }
            }

            lastrow--;

            // first col

            if (firstcol <= lastcol)
            {
                for (int i = lastrow; i >= firstrow; i--)
                {
                    v.push_back(matrix[i][firstcol]);
                }
            }

            firstcol++;
        }

        return v;
    }
};