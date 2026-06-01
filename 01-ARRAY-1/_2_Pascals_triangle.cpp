// Question.2:
// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Leetcode:118:

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>triangle(numRows);
        for(int i=0;i<numRows;i++){
            triangle[i].resize(i+1);
            triangle[i][0]=triangle[i][i]=1;

            for(int j=1;j<i;j++){
                triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
            }

        }
        return triangle;

    }
};

### Complexity Analysis

- **Time Complexity:** `O(n²)`

  The triangle contains `1 + 2 + 3 + ... + n = n(n + 1)/2` elements, and each element is computed once.

- **Space Complexity:** `O(n²)`

  The output stores `n(n + 1)/2` elements.
