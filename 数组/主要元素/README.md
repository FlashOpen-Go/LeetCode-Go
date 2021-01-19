# 主要元素

## 题目描述
数组中占比超过一半的元素称之为主要元素。给定一个整数数组，找到它的主要元素。若没有，返回-1。

```cpp
示例 1：
输入：[1,2,5,9,5,9,5,5,5]
输出：5
 

示例 2：
输入：[3,2]
输出：-1
 

示例 3：
输入：[2,2,1,1,1,2,2]
输出：2
```

## 解析
- 不考虑暴力破解
- 首先对数组进行排序，如果存在这个数，那么这个数一定是在数组的中间位置
- 那么只需要对排序后的数组进行计数即可

## 实现
#### CPP
```CPP
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        sort(nums.begin(), nums.end());     //排序
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            // 循环数组，对中间位置元素进行计数
            if (nums[i] == nums[nums.size() / 2])
            {
                count++;
            }
        }
        if (count > (nums.size() / 2))
            return nums[nums.size() / 2];
        return -1;
    }
};
```