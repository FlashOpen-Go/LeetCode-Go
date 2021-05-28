# 面试题 02.01. 移除重复节点

## 题目描述
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

#### 示例1:
> 输入：[1, 2, 3, 3, 2, 1]
> 输出：[1, 2, 3]

#### 示例2:
> 输入：[1, 1, 1, 1, 2]
> 输出：[1, 2]

##### 提示：
> 链表长度在[0, 20000]范围内。
> 链表元素在[0, 20000]范围内。

##### 进阶：
> 如果不得使用临时缓冲区，该怎么解决？

## 解析
### 方法1：
- 定义记录数组，遍历链表判断数据是否已经出现

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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head== NULL || head->next == NULL)
            return head;
        vector<bool>array(20001, false);
        ListNode* q = new ListNode(0);
        ListNode* new_head = q;
        ListNode* p = head;
        while(p != NULL)
        {
            if (!array[p->val])
            {
                array[p->val] = true;
                new_head->next = p;
                new_head = new_head->next;
                p = p->next;
                new_head->next = NULL;
            }
            else
                p = p->next;
        }
        return q->next;
    }
};
```
#### Python3
```python
class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        val_set=set()   # 利用set保存不重复的节点
        prev=ListNode(-1)
        prev.next=head
        while prev.next:
            if prev.next.val in val_set:
                prev.next=prev.next.next
            else:
                val_set.add(prev.next.val)
                prev=prev.next
        return head
```