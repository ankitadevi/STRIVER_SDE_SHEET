// Question:Find the duplicate in an array of N+1 integers
// Problem Statement: Given an array of N + 1 size, where each element is between 1 and N. 
// Assuming there is only one duplicate number, your task is to find the duplicate number.
//leetcode:287  link: https://leetcode.com/problems/find-the-duplicate-number/description/

// binary search
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            int count = 0;
            for(int x : nums) {
                if(x <= mid) count++;
            }

            if(count > mid)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

// TC: O(n log n)
// SC: O(1)

// Floyd's Cycle Detection
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Find meeting point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Find duplicate number
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

// TC : 0(n)
// SC : 0(1)    

// For interviews, Floyd's Cycle Detection is considered the optimal solution, 
// while Binary Search on Answer is the best alternative that also satisfies all constraints.
