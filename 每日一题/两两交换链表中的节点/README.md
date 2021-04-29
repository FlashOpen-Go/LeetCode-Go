# 24. 两两交换链表中的节点

## 题目描述
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

### 示例 1：
<img src="https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg">
```
输入：head = [1,2,3,4]
输出：[2,1,4,3]
```
### 示例 2：
```
输入：head = []
输出：[]
```
### 示例 3：
```
输入：head = [1]
输出：[1]
```
 

### 提示：

 - 链表中节点的数目在范围 [0, 100] 内
 - 0 <= Node.val <= 100

### 解析
 - 用一个变量遍历链表访问位置
 - 如果时偶数位就调换位置




## 代码实现
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
    int idx=0;
    public ListNode swapPairs(ListNode head) {
        if(head==null||head.next==null) return head;
		//如果是偶数位就调换位置
		if(idx%2==0) {
			int temp = head.next.val;
			head.next.val = head.val;
			head.val = temp;
		}
		idx++;
        head.next = swapPairs(head.next);
		return head;
    }
};
```