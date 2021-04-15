# 剑指 Offer 53 - II. 0～n-1中缺失的数字

## 题目描述
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
 
```c
示例 1:
输入: [0,1,3]
输出: 2

示例 2:
输入: [0,1,2,3,4,5,6,7,9]
输出: 8

限制：
1 <= 数组长度 <= 10000
```

## 解析
#### 方法一
- 由于是 0 到 n-1，并且数据是有序的，因此可以利用下标和数据进行匹配

## 代码实现
### CPP
```C++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int count = nums.size();
        for (int i = 0; i < count; i++)
        {
            if (i != nums[i])
            {
                return i;
            }
        }
        return (nums[count - 1] + 1);
    }
};
```
#### Python3
```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        sum1 = 0
        if not 0 in nums: return 0 
        for i in nums: sum1 += i
        sum2 = n * (n+1) / 2
        a = int(sum2-sum1)  # 求和根据差值获取缺失的数
        if a in nums: return n
        return a
```