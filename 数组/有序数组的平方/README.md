# 有序数组的平方

## 题目描述
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

```c
示例 1：
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]

示例 2：
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
 

提示：
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 已按 非递减顺序 排序
```

## 解析
- 最简单的方法就是将数组的数先进行平方，之后再进行排序。

## 实现
#### CPP
```C++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret;
        for (int num : nums)
            ret.push_back(num * num);
        sort(ret.begin(), ret.end());
        return ret;
    }
};
```