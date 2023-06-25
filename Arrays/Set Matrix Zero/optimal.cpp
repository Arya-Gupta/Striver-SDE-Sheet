/*
Time Complexity - Since we are iterating through the entire matrix, time taken is O(N).

Space Complexity - Since we are not taking any extra space, space complexity is O(1).

Explanation - Instead of maintaining separate vectors, we use the first row and column as the vectors to mark which cells are to be set to 0.
We perform operations on row 0 and column 0 after all the cells from (1, 1) upto (row - 1, col - 1) have been set using row 0 and column 0 because row 0 and column 0 are used for marking purposes.
While performing operations on row 0 and column 0, we need something to keep a record of whether either of them should be turned to 0 based on whether they initially contained any 0 before the marking takes place.
For row 0 we use matrix[0][0] and for column 0 we use a separate variable x.
Thus while performing operations on row 0 and column 0 to 0, we must act on row 0 first before column 0 - because if x sets matrix[0][0] to 0 when it was initially 1, row 0 will now be incorrectly converted to 0 based upon the new value of matrix[0][0].
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), x = 1;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0; // mark i-th row to be set to 0
                    if(j != 0) matrix[0][j] = 0; // mark j-th row to be set to 0
                    else x = 0; // if the cell lies in column 0, we change x to 0
                }
            }
        }

        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // first convert row and then convert column because column is being converted according to x
        // if x causes matrix[0][0] to change to 0 we can get a wrong answer

        // if matrix[0][0] = 0, change the first row to 0
        if(matrix[0][0] == 0){
            for(int j = 0; j < col; j++){
                matrix[0][j] = 0;
            }
        }

        // if x = 0, change the first column to 0
        if(x == 0){
            for(int i = 0; i < row; i++){
                matrix[i][0] = 0;
            }
        }
    }
};