# 旋转链表

## 题目描述
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

 

#### 示例 1：
![](https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg)
> 输入：head = [1,2,3,4,5], k = 2
> 输出：[4,5,1,2,3]

#### 示例 2：
![](https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg)
> 输入：head = [0,1,2], k = 4
> 输出：[2,0,1]
 

##### 提示：
- 链表中节点的数目在范围 [0, 500] 内
- -100 <= Node.val <= 100
- 0 <= k <= 2 * 109

## 解析
### 方法1：双指针
- 首先遍历链表，计算链表长度
- 之后将链表成环
- 计算新的头节点位置 n = length - (n % length)
- 移动头节点和为节点指针
- 断开尾节点

## 代码实现
### 方法1：双指针
#### CPP
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        int length = 0;
        ListNode* New_head = head;
        ListNode* p = head;
        while(p->next != nullptr)
        {
            length++;
            p = p->next;
        }
        length++;
        p->next = head;
        k %= length;
        k = length - k;
        while( k != 0)
        {
            New_head = New_head->next;
            p = p->next;
            k--;
        }
        p->next = nullptr;
        return New_head;
    }
};
```