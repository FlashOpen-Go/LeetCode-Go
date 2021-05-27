# 216. 组合总和 III

## 题目描述
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

### 说明：

 - 所有数字都是正整数。
 - 解集不能包含重复的组合。 
### 示例 1:
```
输入: k = 3, n = 7
输出: [[1,2,4]]
```
### 示例 2:
```
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
```

### 解析
 - 利用回溯算法加上剪枝去重





## 代码实现
```Java
class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<>();
		combination(res, new ArrayList<>(),k,n,0);
		return res;
    }
    public void combination(List<List<Integer>> res, List<Integer> list,int k, int n, int idx) {
		if(n<=0) {
			if(n==0&&list.size()==k) {
				res.add(new ArrayList<>(list));
			}
			return;
		}
		for(int i=idx+1;i<=9;i++) {
			list.add(i);
			combination(res, list,k,n-i,i);
			list.remove(list.size()-1);
		}
	}
};
```