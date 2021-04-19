# 三个数的最大乘积

## 题目描述
给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积

```c
示例 1：
输入：nums = [1,2,3]
输出：6

示例 2：
输入：nums = [1,2,3,4]
输出：24

示例 3：
输入：nums = [-1,-2,-3]
输出：-6


提示：
3 <= nums.length <= 104
-1000 <= nums[i] <= 1000
```

## 分析
- 首先对数组进行排序
- 如果全为正数或全为负数，那么最大的乘机一定是最后三个元素的乘积
- 如果存在正数负数混合，那么一定是开始的两个数和最后一个数的乘积，前两个如果全是负数相乘后为正数
- 所以只需要在两种情况中查找最大值即可

## 代码
### CPP
```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return max(nums[n - 1] * nums[n - 2] * nums[ n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};
```
### Java
```Java
public class MaxNum {	
	public static int getMaxNum(int[] nums) {
		Arrays.parallelSort(nums);
		return  Math.max(nums[nums.length-1]*nums[nums.length-2]*nums[nums.length-3], nums[0]*nums[1]*nums[nums.length-1]);
	}
}
```
#### Python3
```python
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort()     # 数组进行升序排列
        a = nums[-1] * nums[-2] * nums[-3]  # 排序后最后三个数最大
        b = nums[0] * nums[1] * nums[-1]    # - - + 的情况
        return max(a, b)
```
