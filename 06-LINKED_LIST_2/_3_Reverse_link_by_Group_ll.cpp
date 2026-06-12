// Brute-force
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(!head || k==1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* tail = dummy;
        ListNode* curr = head;

        while(curr){

            stack<ListNode*> st;

            ListNode* temp = curr;
            int cnt = 0;

            while(temp && cnt < k){
                st.push(temp);
                temp = temp->next;
                cnt++;
            }

            if(cnt < k){
                tail->next = curr;
                break;
            }

            while(!st.empty()){
                tail->next = st.top();
                st.pop();
                tail = tail->next;
            }

            tail->next = temp;
            curr = temp;
        }

        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(k) (or O(N) in worst case)

// optimal 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(!head || k==1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroup = dummy;

        while(true){

            ListNode* kth = prevGroup;

            for(int i=0;i<k && kth;i++){
                kth = kth->next;
            }

            if(!kth) break;

            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* curr = prevGroup->next;

            while(curr != groupNext){

                ListNode* nxt = curr->next;

                curr->next = prev;

                prev = curr;
                curr = nxt;
            }

            ListNode* temp = prevGroup->next;

            prevGroup->next = kth;

            prevGroup = temp;
        }

        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(1)
