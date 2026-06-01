
// Question1 :Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// leetcode:73
//tc:O(m*n)
//sc:O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]||col[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
//another optimal
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = 1;

        // Step 1: Mark rows and columns
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {

                    matrix[i][0] = 0;  // mark row

                    if(j != 0)
                        matrix[0][j] = 0; // mark column
                    else
                        col0 = 0; // first column contains a zero
                }
            }
        }

        // Step 2: Update matrix using markers
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle first row
        if(matrix[0][0] == 0) {
            for(int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle first column
        if(col0 == 0) {
            for(int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

//tc:O(m*n)
//sc:O(1)
