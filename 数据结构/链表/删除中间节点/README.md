# 删除中间节点

## 题目描述
实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。

```c
示例：

输入：单向链表a->b->c->d->e->f中的节点c
结果：不返回任何数据，但该链表变为a->b->d->e->f
```

## 解析
### 方法1
由于只能访问当前元素，所以只能将后面的值赋给前一个位置，最后再删除第最后一个。

### 方法2
将给定节点的后一个节点的值赋给当前节点值，之后再删除后一个即可。

## 实现
### CPP
```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define F1
class Solution {
public:
    void deleteNode(ListNode* node) {
#ifndef F1
        while(node->next->next != NULL)
        {
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        node->next = NULL;
#else
        node->val = node->next->val;
        node->next = node->next->next;
#endif
    }
};
```