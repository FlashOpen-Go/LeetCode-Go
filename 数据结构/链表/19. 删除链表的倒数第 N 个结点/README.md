# 19. 删除链表的倒数第 N 个结点

## 题目描述
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

 

###示例 1：
<img src="https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg" alt>
```
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```
### 示例 2：
```
输入：head = [1], n = 1
输出：[]
```
### 示例 3：
```
输入：head = [1,2], n = 1
输出：[1]
```
 

### 提示：

 - 链表中结点的数目为 sz
 - 1 <= sz <= 30
 - 0 <= Node.val <= 100
 - 1 <= n <= sz

## 解析
### 双指针实现
- 定义两个指针，初始化时均指向链表的头结点的上一个节点
- 首先将先行指针向后移动需要查找的位置的次数
- 再将两个指针一起移动
- 返回头结点

## 实现
### Java
```Java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null){
            return  null;
        }
        ListNode realHead = new ListNode(0, head);
		ListNode fast = realHead,slow = realHead;
		int curr = 0;
		while(fast!=null) {
			fast = fast.next;
			if(curr>n) {
				slow = slow.next;
			}
            curr++;
		}
		slow.next = slow.next.next;
		return realHead.next;
    }
};
```