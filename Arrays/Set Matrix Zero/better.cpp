/*
Time Complexity - Since we are iterating through the entire matrix, time taken is O(N).

Space Complexity - Since we are creating vectors of size row and column, space taken is O(row + column).

Explanation - Instead of storing the 0 indexes in a vector, or changing the cells to -1, we maintain two vectors to mark the cells which are to be set to 0.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> r(row, 0); // used to mark rows to be set to 0
        vector<int> c(col, 0); // used to mark columns to be set to 0
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    r[i] = 1; // marking row to be set to 0
                    c[j] = 1; // marking column to be set to 0
                }
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(r[i] || c[j]) matrix[i][j] = 0;
            }
        }
    }
};