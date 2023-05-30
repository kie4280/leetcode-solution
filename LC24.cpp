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
  ListNode *swapPairs(ListNode *head) {
    ListNode *cur = head;
    ListNode *prev = nullptr;
    bool f_swap = true;
    while (cur) {
      ListNode *p1 = cur, *p2 = cur->next;
      if (f_swap) {
        ListNode *next;
        if (p2) {
          p1->next = p2->next;
          p2->next = p1;
          next = p2;
        } else {
          next = p1;
        }
        if (prev == nullptr) {
          head = next;
        } else {
          prev->next = next;
        }
      }
      prev = cur;
      cur = cur->next;
      f_swap = ~f_swap;
    }
    return head;
  }
};
