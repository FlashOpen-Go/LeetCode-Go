# 删除排序链表中的重复元素 II

## 题目描述
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。

返回同样按升序排列的结果链表。

 

#### 示例 1：
![](linkedlist1.jpg)
```C
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
```

#### 示例 2：
![](linkedlist2.jpg)
```C
输入：head = [1,1,1,2,3]
输出：[2,3]
```

##### 提示：
```C
链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序排列
```

## 解析
#### 方法1：
- 创建一个虚拟的头节点
- 之后遍历链表，判断next 和 next->next 的值是否相同
- 如果相同则记录该值，并删除与该值相同的节点
- 如果不同则将进入下一个元素

## 代码实现
#### 方法1：
##### CPP
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* new_head = new ListNode();
        new_head->next = head;
        ListNode* p = new_head;
        while(p->next != nullptr && p->next->next != nullptr)
        {
            if (p->next->val == p->next->next->val)
            {
                int temp = p->next->val;
                while(p->next != nullptr && p->next->val == temp)
                {
                    p->next = p->next->next;
                }
            }
            else
            {
                p = p->next;
            }
        }
        return new_head->next;
    }
};
```