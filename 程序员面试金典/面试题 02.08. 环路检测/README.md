# 面试题 02.08. 环路检测

## 题目描述
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

进阶：

你是否可以使用 O(1) 空间解决此题？
 

##### 示例 1：
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png)
> 输入：head = [3,2,0,-4], pos = 1
> 
> 输出：返回索引为 1 的链表节点
> 
> 解释：链表中有一个环，其尾部连接到第二个节点。

##### 示例 2：
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png)
> 输入：head = [1,2], pos = 0
> 
> 输出：返回索引为 0 的链表节点
>
> 解释：链表中有一个环，其尾部连接到第一个节点。

##### 示例 3：
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png)
> 输入：head = [1], pos = -1
>
> 输出：返回 null
>
> 解释：链表中没有环。
 

##### 提示：
- 链表中节点的数目范围在范围 [0, 104] 内
- -105 <= Node.val <= 105
- pos 的值为 -1 或者链表中的一个有效索引

## 解析
### 双指针
- 首先需要判断该链表是否为相交链表
- 需要两个指针来进行判断
- fast：每次移动两个位置
- slow ： 每次移动一个位置
- 如果两个链表是相交的，那么fast和slow一定会相遇
- 当fast和slow相遇时
    - 设 slow走的路程为 n，那么 fast 走的路程则为2n
    - 那么这个环的长度的整数倍一定为 2n - n = n
    - 设slow在进入环前走的 x 步，那么当前在环中的位置则为 n - x
    - 这时创建指针 p 并指向链表头部
    - p 和 slow 同时前进，那么在 p 走了 x 步后则达到入环位置
    - 此时 slow 走了 x + (n - 1) = n，恰好slow也是在入环位置
    - 那么此时 p 和 slow 时相等的，因此该位置便是环开始位置


## 代码实现
### 双指针
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* p = head;
        do
        {
            if (fast->next == NULL || fast->next->next == NULL)
                return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }while(fast != slow);
        while(p != slow)
        {
            p = p->next;
            slow = slow->next;
        }
        return p;
    }
};
```