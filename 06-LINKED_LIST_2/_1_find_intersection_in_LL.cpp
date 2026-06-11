// brute-force
// For every node in list A, traverse the entire list B and check whether the node addresses are the same.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* currA = headA;

        while (currA) {
            
            ListNode* currB = headB;

            while (currB) {
                if (currA == currB) {
                    return currA;
                }
                currB = currB->next;
            }

            currA = currA->next;
        }

        return NULL;
    }
};
// Time Complexity: O(m × n)
// For each node of list A, we traverse all nodes of list B.
// Space Complexity: O(1)

// optimal
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        return a; // intersection node or NULL
    }
};
// Complexity
// Time: O(m + n)
// Space: O(1)
