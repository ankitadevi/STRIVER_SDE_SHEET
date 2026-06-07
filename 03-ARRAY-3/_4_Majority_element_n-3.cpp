// Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array
// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

//leetcode:229  link:https://leetcode.com/problems/majority-element-ii/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        //brute force approach
        //time limit exceed
        // set<int>v;
        // for(int i=0;i<nums.size();i++){
        //     int count=0;
        //     for(int j=0;j<nums.size();j++){
        //         if(nums[i]==nums[j]){
        //             count++;
        //         }
        //     }

        //     if(count>(nums.size()/3)){
        //         v.insert(nums[i]);
        //     }
        // }
        // vector<int>v1;
        // for(auto a:v){
        //     v1.push_back(a);
        // }

        // return v1;



        //Better Approach
        //using map and vector
        // vector<int>v;
        // map<int,int>m;
        // int n=nums.size();
        // int r=int(n/3)+1;
        // for(int i=0;i<n;i++){
        //     m[nums[i]]++;
        //     if(m[nums[i]]==r){
        //         v.push_back(nums[i]);
        //     }
        // }
        // return v;



    //optimised solution:
    class Solution {
    public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;

        // Find potential candidates
        for (int num : nums) {
            if (num == ele1) {
                cnt1++;
            }
            else if (num == ele2) {
                cnt2++;
            }
            else if (cnt1 == 0) {
                ele1 = num;
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                ele2 = num;
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Verify candidates
        cnt1 = cnt2 = 0;

        for (int num : nums) {
            if (num == ele1) cnt1++;
            else if (num == ele2) cnt2++;
        }

        vector<int> ans;
        int n = nums.size();

        if (cnt1 > n / 3) ans.push_back(ele1);
        if (cnt2 > n / 3) ans.push_back(ele2);

        return ans;
    }
};

// tc : O(n)
// sc : O(1)
