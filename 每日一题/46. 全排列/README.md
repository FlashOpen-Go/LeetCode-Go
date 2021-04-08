# 46. 全排列

## 题目描述
给定一个 没有重复 数字的序列，返回其所有可能的全排列。


### 示例 1：
```
输入：[1,2,3]
输出：1
```
### 示例 2：
```
输入：nums = [2,2,2,0,1]
输出：
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

### 思路：
- 回溯算法





## 代码实现
#### Java
```Java
class Solution {
    List<List<Integer>> res = new LinkedList<>();
    public List<List<Integer>> permute(int[] nums) {
        //track记录选择的路径
		LinkedList<Integer> track = new LinkedList<Integer>();
		backtrack(nums, track);
		return res;
    }
    public  void backtrack(int[] nums ,LinkedList<Integer> track) {
		//如果track的长度和nums长度相等，说明这条路已经到头了
		if(track.size()==nums.length) {
			res.add(new LinkedList(track));
			return;
		}
		for(int i=0;i<nums.length;i++) {
			//如果这个数存在于track，说明已经选过，跳过选择下一个
			if(track.contains(nums[i])) {
				continue;
			}
			//加入已经走的路径
			track.add(nums[i]);
			backtrack(nums, track);
			//返回已经走得路径，以便下一个选择继续走
			track.removeLast();
		}
	}
};
```