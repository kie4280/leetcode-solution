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
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    ListNode *next, *head2;
    head2 = head->next;
    head->next = nullptr;
    while (head2 != nullptr) {
      next = head2->next;
      head2->next = head;
      head = head2;
      head2 = next;
    }
    return head;
  }
};
