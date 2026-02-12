#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect if cycle exists
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;          // move 1 step
            fast = fast->next->next;    // move 2 steps

            if(slow == fast) {          // cycle detected
                // Step 2: Find starting node of cycle
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;  // starting node of cycle
            }
        }
        return NULL;  // no cycle
    }
};

int main() {

    // Creating nodes
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating a cycle (5 -> 3)
    fifth->next = third;

    Solution obj;
    ListNode* cycleStart = obj.detectCycle(head);

    if(cycleStart != NULL)
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle detected." << endl;

    return 0;
}
