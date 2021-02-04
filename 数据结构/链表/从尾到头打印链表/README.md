# 从尾到头打印链表

## 题目描述
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

```c
示例 1：
输入：head = [1,3,2]
输出：[2,3,1]
 
限制：
0 <= 链表长度 <= 10000
```

## 解析
- 遍历链表，添加到数组中，再反序数组

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
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode* p = head;
        vector<int> ret;
        while(p != NULL)
        {
            ret.push_back(p->val);
            p = p->next;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```