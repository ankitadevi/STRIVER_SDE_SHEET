// 4 Sum | Find Quads that add up to a target value
// Problem Statement: Given an array of N integers, your task is to find unique quads that add up 
// to give a target value. In short, you need to return an array of all the unique quadruplets 
// [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

//Leetcode:18   link:https://leetcode.com/problems/4sum/description/


#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        //Brute force O(n^4)
        // set<vector<int>>answer;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             for(int l=k+1;l<n;l++){
        //                 long long sum=nums[i]+nums[j];
        //                 sum+=nums[k];
        //                 sum+=nums[l];
        //                 if(sum==target){
        //                     vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
        //                     sort(temp.begin(),temp.end());
        //                     answer.insert(temp);
        //                 }
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>>ans={answer.begin(),answer.end()};
        // return ans;


    //Optimised Solution using two pointers
    class Solution {
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum =
                        (long long)nums[i] +
                        nums[j] +
                        nums[left] +
                        nums[right];

                    if (sum == target) {
                        ans.push_back(
                            {nums[i], nums[j], nums[left], nums[right]}
                        );

                        left++;
                        right--;

                        while (left < right &&
                               nums[left] == nums[left - 1])
                            left++;

                        while (left < right &&
                               nums[right] == nums[right + 1])
                            right--;
                    }
                    else if (sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};

// tc:0(n^3)
// sc:0(1)

// Pattern

// This is a direct extension of Two Sum → 3Sum → 4Sum:

// Two Sum → Hash Map / Two Pointers → O(n)
// 3Sum → Fix one + Two Pointers → O(n²)
// 4Sum → Fix two + Two Pointers → O(n³)
