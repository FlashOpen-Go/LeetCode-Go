class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def mergeTwoLists(l1:ListNode, l2:ListNode):
    if l1 == None:
        return l2
    if l2 == None:
        return l1
    
    ret_list = None

    if l1.val < l2.val:
        ret_list = l1
        ret_list.next = mergeTwoLists(l1.next, l2)
    else:
        ret_list = l2
        ret_list.next = mergeTwoLists(l1, l2.next)
    return ret_list