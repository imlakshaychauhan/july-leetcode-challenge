// https://leetcode.com/problems/reverse-linked-list-ii/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* tail = dummy, *curr = head;
        int pos = 1;
        while(pos <= right)
            if(pos < left) {
                tail = curr;
                curr = curr->next;
                pos++;
            }
            else {
                ListNode* start = curr, *prev = nullptr;
                while(pos <= right && curr) {
                    ListNode* nextt = curr->next;
                    curr->next = prev;
                    prev = curr; curr = nextt;
                    pos++;
                }
                tail->next = prev;
                start->next = curr;
            }
        return dummy->next;
    }
};