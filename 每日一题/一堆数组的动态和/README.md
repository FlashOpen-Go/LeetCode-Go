# 一堆数组的动态和

## 题目描述
给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。

请返回 nums 的动态和。

### 示例 1：
```
输入：nums = [1,2,3,4]
输出：[1,3,6,10]
解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4]
```

###示例 2：
```
输入：nums = [1,1,1,1,1]
输出：[1,2,3,4,5]
解释：动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1]
```

### 示例 3：
```
输入：nums = [3,1,2,10,1]
输出：[3,4,6,16,17]
```

### 提示：
- 1 <= nums.length <= 1000
- -10^6 <= nums[i] <= 10^6

## 代码实现
#### Python3
```python
class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if len(nums) >= 1:  # 判断数组长度是否符合计算要求
            if isinstance(nums[0], int): # 判断数组类型是否符合计算要求
                rtype = [nums[0]]
                for i in range(1, len(nums)):
                    if isinstance(nums[i], int):
                        total = rtype[i-1] + nums[i]
                        rtype.append(total)
                    else:
                        return '数据类型错误'
                return rtype
            else:
                return '数据类型错误'
        else:
            return 'nums数组长度为0'
```