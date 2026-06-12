// Brute-Force
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL || k == 0)
            return head;

        int len = 0;
        ListNode* temp = head;

        while(temp){
            len++;
            temp = temp->next;
        }

        k = k % len;

        while(k--){

            ListNode* prev = NULL;
            ListNode* curr = head;

            while(curr->next){
                prev = curr;
                curr = curr->next;
            }

            // curr = last node
            // prev = second last node

            prev->next = NULL;
            curr->next = head;
            head = curr;
        }

        return head;
    }
};
// Time: O(N × K)
// Space: O(1)

// Optimal
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL || k == 0)
            return head;

        int len = 1;
        ListNode* tail = head;

        while(tail->next){
            tail = tail->next;
            len++;
        }

        k = k % len;

        if(k == 0)
            return head;

        // Make circular list
        tail->next = head;

        int steps = len - k;

        ListNode* newTail = head;

        for(int i = 1; i < steps; i++){
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;

        newTail->next = NULL;

        return newHead;
    }
};
// Time: O(N)
// Space: O(1)
