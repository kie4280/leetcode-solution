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
  int pairSum(ListNode *head) {
    ListNode *mid = head;
    ListNode *it = head;
    while (it != nullptr && it->next != nullptr) {
      mid = mid->next;
      it = it->next->next;
    }
    ListNode *prev = nullptr;
    ListNode *cur = mid;
    ListNode *next;
    while (cur != nullptr) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    int maxx = 0;
    it = head;
    while (prev) {
      maxx = max(it->val + prev->val, maxx);
      prev = prev->next;
      it = it->next;
    }
    return maxx;
  }
};
