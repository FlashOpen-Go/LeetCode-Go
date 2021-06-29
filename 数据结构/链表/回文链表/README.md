# 回文链表

## 题目描述
请判断一个链表是否为回文链表。

#### 示例 1:
> 输入: 1->2
> 输出: false

#### 示例 2:
> 输入: 1->2->2->1
> 输出: true

#### 进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

## 解析
### 方法1：栈
- 第一次遍历链表将元素压栈
- 第二次遍历，同时将栈内元素弹出，比较是否相同


## 代码实现
### 方法1：栈
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
    bool isPalindrome(ListNode* head) {
        bool ret = true;
        if (head == nullptr || head->next == nullptr)
            return ret;
        vector<int>array;
        ListNode* p = head;
        while(p != nullptr)
        {
            array.push_back(p->val);
            p = p->next;
        }
        p = head;
        while( p!= nullptr)
        {
            if (p->val != array[array.size() - 1])
                return false;
            p = p->next;
            array.pop_back();
        }
        return true;
    }
};
```