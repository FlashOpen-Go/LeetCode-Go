# 53. 最大子序和

## 题目描述
给你一个字符串 s，找到 s 中最长的回文子串。

 

### 示例 1：
```
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
```
### 示例 2：
```
输入：nums = [1]
输出：1
```
### 示例 3：
```
输入：nums = [0]
输出：0
```
### 示例 4：
```
输入：nums = [-1]
输出：-1
```
### 示例 5：
```
输入：nums = [-100000]
输出：-100000
```
### 提示：

 - 1 <= nums.length <= 3 * 104
 - -105 <= nums[i] <= 105

## 解析
- 要取n位为止的最大值，只需要取n-1位的最大值再加上nums[n]就行了
- 用一个数pre维护n-1位的子序列最大值就ok了
- res出n位最大子序列



## 代码实现
```Java
class Solution {
    public int maxSubArray(int[] nums) {
        int pre=0;
		int res=Integer.MIN_VALUE;
		for(int n:nums) {
			//当n>n+pre说明pre<0,这时候去掉pre，从n开始累加
			pre = Math.max(pre+n,n);
            //取n位截至最大值和历史最大值比较取最大值
			res = Math.max(res, pre);		
		}
		return res;
    }
};
```