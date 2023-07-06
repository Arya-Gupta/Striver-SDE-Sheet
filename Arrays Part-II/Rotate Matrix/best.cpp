/*
Time Complexity - Iterating through the array takes O(N) time.

Space Complexity - Since transpose is performed in-place, space taken is O(1).

Explanation - Transpose a matrix: https://takeuforward.org/data-structure/transpose-a-matrix-program-01-space/
First we transpose the matrix and then reverse each row.
Transpose is performed in place, so no extra space is required.
*/

class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};