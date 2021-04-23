# 面试题 02.04. 分割链表

## 题目描述
编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。如果链表中包含 x，x 只需出现在小于 x 的元素之后(如下所示)。分割元素 x 只需处于“右半部分”即可，其不需要被置于左右两部分之间。

#### 示例:
> 输入: head = 3->5->8->5->10->2->1, x = 5
> 输出: 3->1->2->10->5->5->8

## 解析
### 方法1：
- 定义两个哑节点，之后遍历链表，将小于X的节点添加到其中一个中，其他的则添加到另一个
- 之后返回两个链表的拼接

## 代码实现
### 方法1：
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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* s = new ListNode(0);
        ListNode* b = new ListNode(0);
        ListNode* s_p = s;
        ListNode* b_p = b;
        ListNode* p = head;
        while(p != NULL)
        {
            if (p->val < x)
            {
                s_p->next = p;
                s_p = s_p->next;
            }
            else
            {
                b_p->next = p;
                b_p = b_p->next;
            }
            p = p->next;
        }
        b_p->next = NULL;
        s_p->next = b->next;
        return s->next;
    }
};
```