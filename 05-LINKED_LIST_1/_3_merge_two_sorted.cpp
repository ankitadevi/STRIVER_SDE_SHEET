// Merge two sorted Linked Lists
// Problem Statement: Given two singly linked lists that are sorted in increasing 
// order of node values, merge two sorted linked lists and return them as a sorted list. 
// The list should be made by splicing together the nodes of the first two lists.

//Leetcode:21   link: https://leetcode.com/problems/merge-two-sorted-lists/solutions/

// A simple brute force approach is:

// Traverse both linked lists.
// Store all values in a vector.
// Sort the vector.
// Create a new linked list from the sorted values.
// Brute Force C++ Solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> nums;

        while (list1) {
            nums.push_back(list1->val);
            list1 = list1->next;
        }

        while (list2) {
            nums.push_back(list2->val);
            list2 = list2->next;
        }

        sort(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        for (int x : nums) {
            tail->next = new ListNode(x);
            tail = tail->next;
        }

        return dummy->next;
    }
};

// Time Complexity: O((n+m) log(n+m))

// Space Complexity: O(n+m) (vector + new nodes)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1.empty()) return list2;
        if(list2.empty()) return list1;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if (list1) tail->next = list1;
        else tail->next = list2;

        return dummy->next;
    }
};

// tc : O(n+m)
// sc : O(1)
