/*
Time Complexity - Time taken to iterate through the matrix is O(N).

Space Complexity - Space taken is O(N) since we are creating a new matrix.

Explanation - The first row becomes the first column, second row becomes second column and so on.
We take a new matrix such that row of previous matrix becomes column of new matrix, and column of previous matrix becomes n - row - 1 of new matrix.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[j][n - i - 1] = matrix[i][j];
            }
        }
        matrix = ans;
    }
};