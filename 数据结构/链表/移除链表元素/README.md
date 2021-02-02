# 移除链表元素

## 题目描述
删除链表中等于给定值 val 的所有节点。

```c
示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
```

## 解析
- 这时一个删除节点的题目，由于是单向链表，所以在删除当前节点的时候，需要知道前一个节点。
- 因此这时需要使用双指针的方法来进行进行遍历。
- 由于被删除的节点可能是头节点，因此这类题目通常会添加一个新的虚拟头节点来进行计算，这样就不需要将头节点作为特殊情况来考虑了。

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* NewHead = new ListNode(); // 新的虚拟头节点
        NewHead->next = head;
        ListNode* p = head;     // 前个节点的指针
        ListNode* q = NewHead;  // 当前节点的指针
        while(p != NULL)
        {
            if (p->val == val)      // 如果值相同，则删除
            {
                q->next = p->next;
                p = q->next;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
        return NewHead->next;
    }
};
```