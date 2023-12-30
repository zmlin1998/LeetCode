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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        if (!(head->next)) return head;

        ListNode *tmp = new ListNode();
        tmp->next = head;
        ListNode *ans = tmp;
        

        while(tmp->next->next){
            ListNode *ptr1 = tmp->next;
            ListNode *ptr2 = tmp->next->next;

            ptr1->next = ptr2->next;
            tmp->next = ptr2;
            ptr2->next = ptr1;

            tmp = ptr1;

            if (!tmp) break;
            if (!(tmp->next)) break;
        }
        return ans->next;
    }
};