// Count inversions in an array
// Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).
// What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

//leetcode:775 link: https://leetcode.com/problems/global-and-local-inversions/description/
//gfg:count inversion  link:https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution {
public:
    long long merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        long long cnt = 0;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                cnt += (mid - left + 1);
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return cnt;
    }

    long long mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;

        long long cnt = 0;

        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += merge(nums, low, mid, high);

        return cnt;
    }

    long long inversionCount(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

// Time Complexity: O(n log n)
// Space Complexity: O(n)
