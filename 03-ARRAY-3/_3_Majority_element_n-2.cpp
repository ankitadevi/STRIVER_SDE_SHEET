// // Find the Majority Element that occurs more than N/2 times
// // Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

// // Leetcode:169  link: https://leetcode.com/problems/majority-element/description/


        //using map
        // map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto a:m){
            if(a.second>nums.size()/2){
                return a.first;
            }
        }
        return 0;


        //Optimised Solution
    class Solution {
    public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }

            if (num == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
};

// tc:0(n)
// sc:0(1)    
