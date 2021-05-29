# 剑指 Offer 22. 链表中倒数第k个节点

## 题目描述
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

 

### 示例：
```
给定一个链表: 1->2->3->4->5, 和 k = 2.
<br>
返回链表 4->5.
```


## 解析
#### 方法1： 暴力破解
- 快慢指针，fast走完k，然后走head，直到fast走完为止，返回head


## 代码实现
### Java
###### 按规律查找
```Java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode fast = head;
		while(fast!=null) {
			fast = fast.next;
			if(k == 0) {
				head = head.next;
			}else {
				k--;
			}
		}
		return head;
    }
}
```