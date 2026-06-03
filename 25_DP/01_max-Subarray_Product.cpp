
// Given an integer array nums, find a subarray
//  that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.

//Leetcode:152  link: https://leetcode.com/problems/maximum-product-subarray/description/

#include<iostream>
using namespace std;

// Brute-Force Aapproach
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //O(n2) tc, O(1) sc
        // int maxi=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     int pro=1;
        //     for(int j=0;j<nums.size();j++){
        //         pro*=nums[j];
        //         maxi=max(pro,maxi);
        //     }
        // }
        // return maxi;

// LeetCode 152: Maximum Product Subarray

// ---------------------------------------------------------
// 1. DP Solution (O(n) Time, O(n) Space)
// State:
// dpMax[i] = Maximum product subarray ending at i
// dpMin[i] = Minimum product subarray ending at i
//
// TC: O(n)
// SC: O(n)
// ---------------------------------------------------------

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> dpMax(n);
        vector<int> dpMin(n);

        dpMax[0] = nums[0];
        dpMin[0] = nums[0];

        int ans = nums[0];

        for(int i = 1; i < n; i++) {

            dpMax[i] = max({
                nums[i],
                nums[i] * dpMax[i - 1],
                nums[i] * dpMin[i - 1]
            });

            dpMin[i] = min({
                nums[i],
                nums[i] * dpMax[i - 1],
                nums[i] * dpMin[i - 1]
            });

            ans = max(ans, dpMax[i]);
        }

        return ans;
    }
};

// ---------------------------------------------------------
// 2. Space Optimized DP (Official Optimal DP)
// State Compression
//
// TC: O(n)
// SC: O(1)
// ---------------------------------------------------------

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] < 0)
                swap(maxProd, minProd);

            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            ans = max(ans, maxProd);
        }

        return ans;
    }
};

// ---------------------------------------------------------
// 3. Prefix-Suffix Product Approach
//
// Idea:
// - Traverse from left to right (prefix)
// - Traverse from right to left (suffix)
// - Reset product when it becomes 0
//
// TC: O(n)
// SC: O(1)
// ---------------------------------------------------------

// I use this approach
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int pre = 1, suf = 1;
        int ans = INT_MIN;

        for(int i = 0; i < n; i++) {

            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;

            pre *= nums[i];
            suf *= nums[n - i - 1];

            ans = max(ans, max(pre, suf));
        }

        return ans;
    }
};
