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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *anchor_l = nullptr, *anchor_r = nullptr;
    anchor_l = head;
    anchor_r = head;
    ListNode *prev = head;
    for (int a=0; a<left-1; ++a) {
      prev = anchor_l;
      anchor_l = anchor_l->next;
    }
    anchor_l = prev;
    for (int a=0; a<right-1; ++a) {
      anchor_r = anchor_r->next;
    }

    ListNode *cur = anchor_l->next, *next = nullptr;
    prev = nullptr;
    while(cur && cur != anchor_r) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    if (anchor_l->next) {
      anchor_l->next->next = anchor_r;
    }
    if (left == 1) {
      head = prev;
    } else {
      anchor_l->next = prev;
    }
    
    
    return head;

  }
};
