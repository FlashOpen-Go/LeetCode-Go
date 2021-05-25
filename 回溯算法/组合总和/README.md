# 39. 组合总和

## 题目描述
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

### 说明：

 - 所有数字（包括 target）都是正整数。
 - 解集不能包含重复的组合。
 
### 示例 1：
```
输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
```
### 示例 2：
```
输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
```

### 提示：

 - 1 <= candidates.length <= 30
 - 1 <= candidates[i] <= 200
 - candidate 中的每个元素都是独一无二的。
 - 1 <= target <= 500

### 解析
 - 利用回溯算法加上剪枝去重





## 代码实现
```Java
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new LinkedList<List<Integer>>();
        //首先给数组排序，这样才能剪枝 
		Arrays.sort(candidates);
        LinkedList<Integer> list = new LinkedList<Integer>(); 
        combination(candidates,list, target,0, res); 
        return res;
    }
    public  void combination(int[] candidates, LinkedList<Integer> list, int target,int idx,List<List<Integer>> res) {
		if (target<=0) {
			if (0 == target) {
                //target等于0就表明list和等于target，就加入到结果集里面
				res.add(new LinkedList<Integer>(list));
			}
			return;
		}
		//从idx开始是为了剪枝，比如2，3，3和3，2，3是一个组合，如果找了3那就不会找2，因为数组排过序，并且下标是从idx开始的
		for (int i =idx;i<candidates.length;i++) {
			list.add(candidates[i]);
			combination(candidates, list, target-candidates[i],i, res);
			list.remove(list.size()-1);
		}
	}
};
```