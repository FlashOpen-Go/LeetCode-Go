# 2. 两数相加

## 题目描述
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。



### 示例 1：
<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/01/02/addtwonumber1.jpg">
```
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
```
### 示例 2：
```
输入：l1 = [0], l2 = [0]
输出：[0]
```
### 示例 3：
```
输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
```

### 提示：

 - 每个链表中的节点数在范围 [1, 100] 内
 - 0 <= Node.val <= 9
 - 题目数据保证列表表示的数字不含前导零

### 解析
 - 新建一个链表
 - 利用t%10复制给新建链表的当前val
 - 利用t/10进位后续和l1.next以及l2.next相加
 - 知道l1和l2不为空且t不为0为止(因为当l1和l2长度相等且最后一位有进位时，如果不判断t不为0就会在最后一位被截断)

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		//初始化一个链表，用户返回
		ListNode temp = new ListNode(-1);
		ListNode pre = temp;
		int t = 0;
		//当l1和l2长度相等且有进位时，就需要判断t是否为0来继续相加
		while(l1!=null||l2!=null||t!=0) {
			if(l1!=null) {
				t+=l1.val;
				l1 = l1.next;
			}
			if(l2!=null) {
				t+=l2.val;
				l2 = l2.next;
			}
			//取余当作当前val
			pre.next = new ListNode(t%10);
			pre = pre.next;
			//取证用作进位
			t = t/10;
		}
		return temp.next;
    }
};
```