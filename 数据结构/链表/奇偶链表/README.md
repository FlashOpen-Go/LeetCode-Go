# 奇偶链表

## 题目描述

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

#### 示例 1:
> 输入: 1->2->3->4->5->NULL
> 输出: 1->3->5->2->4->NULL

#### 示例 2:
> 输入: 2->1->3->5->6->4->7->NULL 
> 输出: 2->3->6->7->1->5->4->NULL

##### 说明:
- 应当保持奇数节点和偶数节点的相对顺序。
- 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

## 解析
### 方法1：三指针
- 初始状态 奇数链表头一定为head         => odd_head
- 初始状态 偶数链表头一定为head->next   => even
- 开始遍历链表，p 指向 第三个节点，也就是 even->next
- 如果节点存在，判断位置的奇偶性
- 如果为奇数，则将当前节点从当前位置删除，之后插入到odd_head后，并更新 odd_head 指针
- 如果为偶数，则更新 even 指针即可


## 代码实现
### 方法1：三指针
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr )
            return head;
        ListNode* odd_head = head;
        ListNode* even = head->next;
        ListNode* p = even->next;
        int i = 3;
        while(p != nullptr)
        {
            if (i % 2)
            {
                even->next = p->next;   //删除P节点
                p->next = odd_head->next;   //尾插法添加到odd中
                odd_head->next = p;     // 更新odd指针
                odd_head = p;   //  更新odd指针
                p = even;       //  回到偶数链表的最后一个节点位置
            }
            else
            {
                even = even->next;  // 更新even指针
            }
            i++;
            p = p->next;
        }
        return head;
    }
};
```