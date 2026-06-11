// Reverse Linked List in groups of Size K
// Problem Statement: Given the head of a linked list, reverse the nodes of the list k at a time, 
// and return the modified list. k is a positive integer and is less than or equal to the length of the 
// linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

//Leetcode:25  link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

// brute-force
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        vector<int> arr;

        ListNode* temp = head;

        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();

        for (int i = 0; i + k <= n; i += k) {
            reverse(arr.begin() + i, arr.begin() + i + k);
        }

        temp = head;
        int idx = 0;

        while (temp) {
            temp->val = arr[idx++];
            temp = temp->next;
        }

        return head;
    }
};

// optimal
class Solution {
public:

    ListNode* findKthNode(ListNode* temp, int k) {
        k -= 1;

        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp) {

            ListNode* kthNode = findKthNode(temp, k);

            if (kthNode == NULL) {
                if (prevLast)
                    prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            ListNode* newHead = reverseList(temp);

            if (temp == head) {
                head = newHead;
            } else {
                prevLast->next = newHead;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};

// Brute Force (vector)     : O(N) Time, O(N) Space
// Optimal Iterative        : O(N) Time, O(1) Space
