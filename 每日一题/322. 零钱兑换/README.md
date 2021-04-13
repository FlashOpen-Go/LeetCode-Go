# 322. 零钱兑换

## 题目描述
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

你可以认为每种硬币的数量是无限的。



###示例 1：
```
输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
```
###示例 2：
```
输入：coins = [2], amount = 3
输出：-1
```
###示例 3：
```
输入：coins = [1], amount = 0
输出：0
```
###示例 4：
```
输入：coins = [1], amount = 1
输出：1
```
###示例 5：
```
输入：coins = [1], amount = 2
输出：2
```


### 思路：
- 暴力数组递归





## 代码实现
#### Java
```Java
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] nums = new int[amount+1];
		Arrays.fill(nums, amount+1);
		nums[0] = 0;
		for(int i=0;i<nums.length;i++) {
			for(int coin:coins) {
				if(i-coin<0) continue;
				nums[i] = Math.min(nums[i], 1+nums[i-coin]);
			}
		}
		return nums[amount]==amount+1?-1:nums[amount];
    }
};
```