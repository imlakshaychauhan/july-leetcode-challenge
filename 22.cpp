// https://leetcode.com/problems/partition-list/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* header = new ListNode(-1);
        ListNode* ptr = header;
        ListNode* tmp = head;
        while(tmp) {
            if(tmp->val < x) {
                ListNode* temp = new ListNode(tmp->val);
                ptr->next = temp;
                ptr = temp;
            }
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp) {
            if(tmp->val >= x) {
                ListNode* temp = new ListNode(tmp->val);
                ptr->next = temp;
                ptr = temp;
            }
            tmp = tmp->next;
        }
        return header->next;
    }
};