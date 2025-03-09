"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return None
        pending_randoms = {}
        i = 0
        new_head = Node(head.val)
        og_list = head
        runner = new_head
        while head:
            if head.random != None:
                pending_randoms.setdefault(head.random, []).append(runner)
            if head.next:
                new_node = Node(head.next.val)
                runner.next = new_node
                runner = runner.next
            head = head.next
        
        runner = new_head
        while og_list:
            if og_list in pending_randoms:
                for r in pending_randoms[og_list]:
                    r.random = runner
            runner = runner.next
            og_list = og_list.next

        return new_head

            
        