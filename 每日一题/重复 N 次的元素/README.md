# 重复 N 次的元素

## 题目描述
在大小为 2N 的数组 A 中有 N+1 个不同的元素，其中有一个元素重复了 N 次。

返回重复了 N 次的那个元素。

#### 示例 1:
```
输入：[1,2,3,3]
输出：3
```
#### 示例 2:
```
输入：[2,1,2,5,3,2]
输出：2
```
#### 示例 3:
```
输入：[5,1,5,2,5,3,5,4]
输出：5
```
提示：
- 4 <= A.length <= 10000
- 0 <= A[i] < 10000
- A.length 为偶数

## 代码实现
#### Python3
```python
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        return max(set(A), key=A.count)
```

#### CPP
```C++
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2] == nums[nums.size() / 2 + 1] ? nums[nums.size() / 2] : nums[nums.size() / 2 - 1];
    }
};
```