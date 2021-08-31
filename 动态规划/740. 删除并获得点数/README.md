# 740. 删除并获得点数

## 题目描述
给你一个整数数组 nums ，你可以对它进行一些操作。

每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。

开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。




### 示例 1：
```
输入：nums = [3,4,2]
输出：6
解释：
删除 4 获得 4 个点数，因此 3 也被删除。
之后，删除 2 获得 2 个点数。总共获得 6 个点数。
```
### 示例 2：
```
输入：nums = [2,2,3,3,3,4]
输出：9
解释：
删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
总共获得 9 个点数。
```


### 提示：

 - 1 <= nums.length <= 2 * 104
 - 1 <= nums[i] <= 104




## 代码实现
#### Java
```Java
class Solution {
    public  int deleteAndEarn(int[] nums) {
		//第一步，首先选择x，那么x-1和x+1都不能选择，因为第一个全部消掉了，结果就是所有的x的和，一次类推
		//类似与打家劫舍问题，每一个位置x抢了，x+1和x-1就不能动了，把原问题转为打家劫舍问题
		int[] trans = new  int[10001];
		for(int i=0;i<nums.length;i++) {
			trans[nums[i]]+=nums[i];
		}
		//动态规划，i位置上最大值，要么是i-1最大值，要么是i-2加上此处值为最大值
		int[] dp = new int[10001];
		dp[0] = trans[0];
		dp[1] = trans[1]>trans[0]?trans[1]:trans[0];
		for(int i=2;i<trans.length;i++) {
			dp[i] = Math.max(dp[i-1], dp[i-2]+trans[i]);
		}
		
		return dp[trans.length-1];
    }
};
```