class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> flaggedCols(cols, 0);
        vector<int> flaggedRows(rows, 0);
        for (int r = 0; r < rows; ++r) {
            for (int i = 0; i < cols; ++i){
                if (matrix[r][i] == 0){
                    flaggedCols[i] = 1;
                    flaggedRows[r] = 1;
                }
            }
        }
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] *= ( 1 - (flaggedRows[i] | flaggedCols[j]));
            }
        }
    }
};