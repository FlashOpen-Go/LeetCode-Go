# 剑指 Offer 56 - II. 数组中数字出现的次数 II

## 题目描述
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

```c
示例 1：
输入：nums = [3,4,3,3]
输出：4

示例 2：
输入：nums = [9,1,7,9,7,9,7]
输出：1

限制：
1 <= nums.length <= 10000
1 <= nums[i] < 2^31
```

## 解析
#### 方法1：
- 首先对数组进行排序
- 之后用三个元素的滑动窗进行检查
- 判断滑动窗的第一个和最后一个元素是否相同
- 如果相同，则滑动窗向后移动，不相等则判断滑动窗中间元素和首位元素的大小关系

## 代码实现
#### CPP
```C++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count = nums.size();
        if (count == 1)
            return nums[0];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < count - 1; i += 3)
        {
            if (nums[i] != nums[i + 2])
            {
                if (nums[i] == nums[i + 1])
                {
                    return nums[i + 2];
                }
                else
                {
                    return nums[i];
                }
            }
        }
        return nums[count - 1];
    }
};
```