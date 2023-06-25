/*
Time Complexity - Since we are iterating through the entire matrix, time taken is O(N).

Space Complexity - Since we are storing all the 0s in a vector, space taken is O(N).

Explanation - We can loop through each element in the matrix and check for elements which are 0s and convert their corresponding entire row and column to 0. 
Given:
1 1 1
1 0 1
1 1 0
Result:
0 0 0
0 0 0
0 0 0
We consider only those 0s that were initially 0. But in this approach, we end up considering elements that have just been turned to 0, thus turning the entire matrix to 0.
Expected result:
1 0 0
0 0 0
0 0 0
Thus we store the position of the initial 0s in a vector of pairs, and then convert onlythe corresponding rows and columns of those initial 0s into 0.

Additionally, we can achieve this without a new vector by converting the 1s into -1s, and converting the -1s into 0s at the end. 
However this would not work in case of negative numbers in the array.
*/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // Loop through matrix
        vector<pair<int, int>> idx;
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                    idx.push_back(make_pair(i, j));
            }
        }

        for (auto p : idx)
        {
            for (int i = 0; i < row; i++)
            {
                matrix[i][p.second] = 0;
            }
            for (int i = 0; i < col; i++)
            {
                matrix[p.first][i] = 0;
            }
        }
    }
};