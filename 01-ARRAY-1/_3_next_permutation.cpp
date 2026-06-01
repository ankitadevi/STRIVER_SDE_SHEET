// Question 4:
// find next lexicographically greater permutation
// Leetcode:31;
//link: https://leetcode.com/problems/next-permutation/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int bp=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                bp=i;
                break;
            }
        }
        if(bp!=-1){
            for(int i=nums.size()-1;i>=0;i--){
                if(nums[bp]<nums[i]){
                    swap(nums[i],nums[bp]);
                    break;
                }
            }
        }
        reverse(nums.begin()+bp+1,nums.end());
    }
};

// tc:O(n)
// sc:O(1)
