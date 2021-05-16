# 有多少小于当前数字的数字

## 题目描述
给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。

以数组形式返回答案。

#### 示例 1:
```
输入：nums = [8,1,2,2,3]
输出：[4,0,1,1,3]
解释： 
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。 
对于 nums[3]=2 存在一个比它小的数字：（1）。 
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
```
#### 示例 2:
```
输入：nums = [6,5,4,8]
输出：[2,1,0,3]
```
#### 示例 3:
```
输入：nums = [7,7,7,7]
输出：[0,0,0,0]
```
提示：

- 2 <= nums.length <= 500
- 0 <= nums[i] <= 100

## 代码实现
#### Python3
```python
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        return [len(list(filter(lambda x: x < i, nums))) for i in nums]
```
#### CPP
```C++
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count_array(101, 0);    //创建元素数组
        vector<int> ret;
        for (int value : nums)  // 统计元素出现的次数
        {
            count_array[value]++;
        }
        for (int i = 1; i < count_array.size(); i++)    // 计算当前元素大于之前元素的个数
        {
            count_array[i] += count_array[i - 1];
        }
        for (int value : nums)  // 计算小于当前数字的数字个数
        {
            ret.push_back(value == 0 ? 0 : count_array[value - 1]);
        }
        return ret;
    }
};
```