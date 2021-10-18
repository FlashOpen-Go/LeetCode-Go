# 剑指 Offer II 024. 反转链表

## 题目描述
给定单链表的头节点 head ，请反转链表，并返回反转后的链表的头节点。

 

#### 示例 1：

![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

> 输入：head = [1,2,3,4,5]
>
> 输出：[5,4,3,2,1]
>

#### 示例 2：
![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

>输入：head = [1,2]
>
>输出：[2,1]
>

#### 示例 3：
> 输入：head = []
>
> 输出：[]
 

#### 提示：
- 链表中节点的数目范围是 [0, 5000]
- -5000 <= Node.val <= 5000


## 解析


## 代码实现
### CPP
```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};
```