# 面试题 02.06. 回文链表


## 题目描述
编写一个函数，检查输入的链表是否是回文的。

#### 示例 1：
> 输入： 1->2
> 输出： false 

#### 示例 2：
> 输入： 1->2->2->1
> 输出： true 
 
##### 进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

## 解析
### 方法1：转化为数组
- 遍历链表将链表转化为数组
- 之后使用双指针来进行判断


## 代码实现
### 方法1：转化为数组
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        vector<int> array;
        ListNode* p = head;
        while(p != NULL)
        {
            array.push_back(p->val);
            p = p->next;
        }
        int left =0;
        int right = array.size() - 1;
        while(left <= right)
        {
            if (array[left] != array[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
```
