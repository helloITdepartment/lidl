# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        c1 = l1
        c2 = l2
        val = (c1.val + c2.val) % 10
        carry = (c1.val + c2.val) // 10
        ret = ListNode(val=val)
        cR = ret

        c1 = c1.next
        c2 = c2.next

        while c1 is not None or c2 is not None:
            c1v = c1.val if c1 is not None else 0
            c2v = c2.val if c2 is not None else 0
            val = (c1v + c2v + carry) % 10
            carry = (c1v + c2v + carry) // 10
            print(c1v, c2v, val, carry)
            n = ListNode(val=val)
            cR.next = n
            cR = cR.next

            c1 = c1.next if c1 is not None else c1
            c2 = c2.next if c2 is not None else c2

        
        if carry is not 0:
            cR.next = ListNode(val=carry)

        return ret


