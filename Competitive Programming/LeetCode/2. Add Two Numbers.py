# 2. Add Two Numbers

# You are given two non-empty linked lists representing two non-negative integers. 
# The digits are stored in reverse order, and each of their nodes contains a single digit. 
# Add the two numbers and return the sum as a linked list.

# You may assume the two numbers do not contain any leading zero, except the number 0 itself.


# Example 1:


# Input: l1 = [2,4,3], l2 = [5,6,4]
# Output: [7,0,8]
# Explanation: 342 + 465 = 807.
# Example 2:

# Input: l1 = [0], l2 = [0]
# Output: [0]
# Example 3:

# Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
# Output: [8,9,9,9,0,0,0,1]
 

# Constraints:

# The number of nodes in each linked list is in the range [1, 100].
# 0 <= Node.val <= 9
# It is guaranteed that the list represents a number that does not have leading zeros.


# Definition for singly-linked list.
class ListNode:
   def __init__(self, val=0, next=None):
      self.val = val
      self.next = next

class Solution:

   def __init__(self):
      self.head = None

   def addTwoNumbers(self, l1, l2):
      dummy = ListNode()

      curr = dummy
      carry = 0
      while l1 or l2 or carry:
         v1 = l1.val if l1 else 0
         v2 = l2.val if l2 else 0

         val = v1+v2+carry
         carry = val // 10
         val = val % 10

         curr.next = ListNode(val)

         curr = curr.next
         l1 = l1.next if l1 else None
         l2 = l2.next if l2 else None

      return curr


if __name__ == '__main__':

   list1 = [2,4,3]
   list2 = [5,6,4]


   # insert item
   l1 = ListNode()
   head = None
   for i in list1:
      l1 = ListNode(i)
      l1.next = head
      head = l1

   
   l2 = ListNode()
   head = None
   for i in list2:
      l2 = ListNode(i)
      l2.next = head
      head = l2



