# 229. 求众数 II

## 题目描述
给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

#### 示例 1:
```
输入：[3,2,3]
输出：[3]
```
#### 示例 2:
```
输入：nums = [1]
输出：[1]
```
#### 示例 3:
```
输入：[1,1,1,3,3,2,2,2]
输出：[1,2]
```
提示：

- 1 <= nums.length <= 5 * 104
- -109 <= nums[i] <= 109

## 代码实现
#### Python3
```python
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        cnt = {}
        ans = []

        for v in nums:
            if v in cnt:
                cnt[v] += 1
            else:
                cnt[v] = 1
        for item in cnt.keys():
            if cnt[item] > len(nums)//3:
                ans.append(item)
        return ans
```