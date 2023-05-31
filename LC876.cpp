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
  ListNode *middleNode(ListNode *head) {
    ListNode *mid = head;
    ListNode *it = head;
    while (it != nullptr && it->next != nullptr) {
      mid = mid->next;
      it = it->next->next;
    }
    return mid;
  }
};
