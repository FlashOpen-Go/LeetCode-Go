# 链表的中间结点

## 题目描述

给定一个头结点为 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。
```c
示例 1：
输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.

示例 2：
输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
 

提示：
给定链表的结点数介于 1 和 100 之间。
```

## 解析
### (1)
- 首先定义一个存储节点指针的数组
- 遍历列表将每个节点存储数组中
- 直接返回数组的中间元素即可
### (2)
 - 快慢指针，快指针走两步，慢指针走一步，等到快指针走结束时返回慢指针

## 代码实现
```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> array;
        ListNode* p = head;
        while(p != NULL)
        {
            array.push_back(p);
            p = p->next;
        }
        return array[array.size() / 2];
    }
};
```
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
    public ListNode middleNode(ListNode head) {
        ListNode p = head;
		ListNode q = head;
		while(q!=null&&q.next!=null) {
			p = p.next;
			q = q.next.next;
		}
		return p;
    }
};
```