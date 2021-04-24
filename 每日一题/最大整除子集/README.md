# 368. 最大整除子集

## 题目描述
给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集```answer``` ，子集中每一元素对 (answer[i], answer[j]) 都应当满足：
 - answer[i] % answer[j] == 0 ，或
 - answer[j] % answer[i] == 0
如果存在多个有效解子集，返回其中任何一个均可。


 

### 示例 1：
```
输入：nums = [1,2,3]
输出：[1,2]
解释：[1,3] 也会被视为正确答案。
```
### 示例 2：
```
输入：nums = [1,2,4,8]
输出：[1,2,4,8]
```

### 提示：

 - 1 <= nums.length <= 1000
 - 1 <= nums[i] <= 2 * 109
 - nums 中的所有整数 互不相同


## 解析
- 先排序数组，然后根据动态规划找出最大子集的最大值以及长度
- 遍历数组，根据下一个最长子集必定是当前子集长度减一，并且当前最大值，必定能整除下一最长子集最大值



## 代码实现
```Java
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        //找出子集最大长度以及子集的最大值
		int[] dp = new int[nums.length];
		//因为最小有一个值，所以设置所有厨师长度为1；
		Arrays.fill(dp, 1);
		//给原数组排序,有序方便找最大值以及最大长度
		Arrays.sort(nums);
		int maxSize = 1;
		int maxVal = dp[0];
        //i从1开始才能保证有子集
		for(int i=1;i<nums.length;i++) {
			for(int j=0;j<i;j++) {
				if(nums[i]%nums[j]==0) {
					dp[i] = Math.max(dp[i], dp[j]+1);
				}
			}
			//如果当前最大长度大于最大长度，设置当前最大长度为最大长度，设置当前最大值为最大值
			if(dp[i]>maxSize) {
				maxSize = dp[i];
				maxVal = nums[i];
			}
		}
		List<Integer> res = new ArrayList<Integer>();
		//如果长度为1，那么只有一个值，返回唯一值
        if(maxSize==1) {
			res.add(nums[0]);
			return res;
		}
		//逆向查找符合当前条件的数组值
		for(int i=nums.length-1;i>=0&&maxSize>0;i--) {
			//如果当前长度为最大值，那么去掉一个最大值，，去掉大最大值必定能整除下一个最大值
            if(dp[i]==maxSize&&maxVal%nums[i]==0) {
				res.add(nums[i]);
                maxVal = nums[i];
				maxSize--;
			}
		}
		return res;
    }
};
```