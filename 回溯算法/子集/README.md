# 78. 子集

## 题目描述
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 

### 示例 1：
```
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```
### 示例 2：
```
输入：nums = [0]
输出：[[],[0]]
```
 

### 提示：

 - 1 <= nums.length <= 10
 - -10 <= nums[i] <= 10
 - nums 中的所有元素 互不相同

### 解析
 - 利用回溯算法加上剪枝去重





## 代码实现
```Java
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
		getSubsets(res, new ArrayList<Integer>(), nums, -1);
		return res;
    }
    public void getSubsets(List<List<Integer>> res, List<Integer> list, int[] nums, int idx) {
		res.add(new ArrayList<>(list));
		for(int i=idx+1;i<nums.length;i++) {
			list.add(nums[i]);
			getSubsets(res, list, nums, i);
			list.remove(list.size()-1);
		}
	}
};
```