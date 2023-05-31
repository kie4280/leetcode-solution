# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head is None:
            return
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        cur = slow
        prev = None
        next = None
        while cur: # reverse linked list
            next = cur.next
            cur.next = prev
            prev = cur
            cur = next
        
        cur = head
        while cur and prev:
            next1 = cur.next
            next2 = prev.next
            cur.next = prev
            prev.next = next1
            prev = next2
            cur = next1
        if cur:
            cur.next = None
