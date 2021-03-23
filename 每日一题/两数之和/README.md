# 1. 两数之和

## 题目描述
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

你可以按任意顺序返回答案。


### 示例 1：
```
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释: 因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```
### 示例 2：
```
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

### 示例 3：
```
输入：nums = [3,3], target = 6
输出：[0,1]
```

###提示：
- 2 <= nums.length <= 103
- 109 <= nums[i] <= 109
- 109 <= target <= 109
- 只会存在一个有效答案



## 代码实现
#### Java
```Java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        List<Integer> list = new ArrayList<Integer>();
		int idx1 = 0;
		int idxval = 0;
		for (int i=0;i<nums.length;i++) {
			//判断target-num在不在list内，如果target-num不在，就把num添加进去
			if(!list.contains(target-nums[i])) {
				list.add(nums[i]);
			//如果target-num再list内，就返回num和target-num
			}else {
				idx1 = i;
				idxval=nums[i];
				break;
			}
		}
		for(int j=0;j<list.size();j++) {
			if(list.get(j)==target-idxval) {
				return new int[] {j,idx1};
			}
		}
		return new int[] {};
    }
};
```