# 删除排序链表中的重复元素


## 题目描述
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。
返回同样按升序排列的结果链表。



#### 示例 1：
![](list1.jpg)
```c
输入：head = [1,1,2]
输出：[1,2]
```

#### 示例 2：
![](list2.jpg)
```c
输入：head = [1,1,2,3,3]
输出：[1,2,3]
```
 

##### 提示：
```
链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序排列
```

## 解析
#### 方法1
- 由于链表是已经排序完成的，因此可以创建一个虚拟头节点，之后遍历链表，向虚拟头节点中添加，添加时判断新链表的最后一个节点值和新添加值是否相同


## 代码实现
#### 方法1
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
        ListNode* new_head = new ListNode(0, head);
        ListNode* p = new_head->next;
        ListNode* q = head->next;
        p->next = NULL;

        while(q != nullptr)
        {
            if (p->val != q->val)
            {
                p->next = q;
                p = q;
                q = q->next;
                p->next = NULL;
            }
            else
            {
                q = q->next;
            }
        }
        return new_head->next;
    }
};
```