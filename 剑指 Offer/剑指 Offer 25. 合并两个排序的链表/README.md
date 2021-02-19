# 剑指 Offer 25. 合并两个排序的链表

## 题目描述
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

```c
示例1：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

限制：
0 <= 链表长度 <= 1000
```


## 解析
#### 方法1： 虚拟头节点
- 创建一个虚拟的头节点，之后遍历两个链表
- 比较两个链表的节点数值大小，依次添加到虚拟节点后，直到两个链表中任意一个为空
- 判断链表是否添加完成，如果没有则添加剩下的到虚拟节点后

## 代码实现
#### CPP
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(); // 创建一个虚拟头节点
        ListNode *q = ret;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while(p1 != NULL && p2 != NULL)  // 循环两个链表，判断大小依次添加
        {
            if (p1->val > p2->val)    
            {
                q->next = p2;
                p2 = p2->next;
            }
            else
            {
                q->next = p1;
                p1 = p1->next;
            }
            q = q->next;
        }
        if (p1 != NULL)     // 判断链表是否添加结束
        {
            q->next = p1;
        }
        if (p2 != NULL)
        {
            q->next = p2;
        }
        return ret->next;
    }
};
```