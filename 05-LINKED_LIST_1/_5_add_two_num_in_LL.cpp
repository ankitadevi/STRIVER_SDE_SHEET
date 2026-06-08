// Add two numbers represented as Linked Lists
// Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers 
// and return the sum as a linked list.


//Leetcode:2  link: https://leetcode.com/problems/add-two-numbers/description/

// Brute-Force
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        long long num1 = 0, num2 = 0;
        long long place = 1;

        while (l1) {
            num1 += l1->val * place;
            place *= 10;
            l1 = l1->next;
        }

        place = 1;

        while (l2) {
            num2 += l2->val * place;
            place *= 10;
            l2 = l2->next;
        }

        long long sum = num1 + num2;

        if(sum == 0) return new ListNode(0);

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(sum){
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            sum /= 10;
        }

        return dummy->next;
    }
};
// Time: O(n + m)
// Space: O(max(n,m)

// Optimal
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        int carry = 0;

        while(l1 || l2 || carry){

            int sum = carry;

            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return dummy->next;
    }
};
// Time: O(max(n,m)
// Space: O(max(n,m)
