/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         // Create a dummy node to simplify the merging process
        ListNode dummy;
        ListNode* tail = &dummy; // This will be the last node in the merged list
        dummy.next = nullptr; // Initialize the next of dummy to nullptr
        // While both lists have nodes to compare
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1; // Append list1 node to the merged list
                list1 = list1->next; // Move to the next node in list1
            } else {
                tail->next = list2; // Append list2 node to the merged list
                list2 = list2->next; // Move to the next node in list2
            }
            tail = tail->next; // Move the tail pointer to the last node
        }
        // If there are remaining nodes in either list, append them
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        // The merged list is next to the dummy node
        return dummy.next;


    }
};