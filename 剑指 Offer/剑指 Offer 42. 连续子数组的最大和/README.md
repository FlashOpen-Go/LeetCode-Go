# 剑指 Offer 42. 连续子数组的最大和

## 题目描述
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
要求时间复杂度为O(n)。

```c
示例1:
输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

提示：
1 <= arr.length <= 10^5
-100 <= arr[i] <= 100
```

## 解析
#### 方法1
- 可以对数据进行累加，然后绘制折线图，之后进行统计，找出最大值即可
- 将之前的进行累加，从第一位开始进行计算
- 如果 nums[ i ] 的值是大于 0 的，那么该值累加之后会增大数值，如果当前值是小于 0 的，那么说明该值的累加是没有意义的
- 这样完成累加之后，再从数组中找出最大值即可


## 代码实现
#### 方法1：
#### CPP
```C++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > 0)
            {
                nums[i] += nums[i - 1];
            }
            ret = max(ret, nums[i]);
        }
        return ret;
    }
};
```
#### Python3
```python
class Solution(object):
    def maxSubArray(self, nums):
        for i in range(1, len(nums)):
            nums[i] += max(nums[i-1], 0)
        return max(nums)
```