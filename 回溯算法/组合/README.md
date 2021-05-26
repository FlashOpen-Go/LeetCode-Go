# 77. 组合

## 题目描述
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

### 示例:
```
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

### 解析
 - 利用回溯算法加上剪枝去重





## 代码实现
```Java
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
		List<Integer> list = new LinkedList<>();
		getCombine(res, list, n, k, 0);
		return res;
    }
    public void getCombine(List<List<Integer>> res, List<Integer> list,int n, int k, int idx) {
		if(0==k) {
			res.add(new LinkedList<>(list));
			return;
		}
        //从idx+1开始是因为一个数字只能出现一次
		for(int i=idx+1;i<=n;i++) {
			list.add(i);
			getCombine(res, list, n, k-1, i);
			list.remove(list.size()-1);
		}
	}
};
```