// Search in a sorted 2D matrix
// Problem Statement: Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.
// Given matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row

//Leetcode:74 link:https://leetcode.com/problems/search-a-2d-matrix/description/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target)
                return true;

            if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;    
    }
};

// Complexity
// Time Complexity: O(log(m*n))
// Space Complexity: O(1)
