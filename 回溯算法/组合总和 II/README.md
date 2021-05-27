# 40. 组合总和 II

## 题目描述
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

### 说明：

 - 所有数字（包括目标数）都是正整数。
 - 解集不能包含重复的组合。 
### 示例 1:
```
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
```
### 示例 2:
```
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
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
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new LinkedList<List<Integer>>();
		//首先给数组排序，这样才能剪枝 
		  Arrays.sort(candidates);
		  LinkedList<Integer> list = new LinkedList<Integer>(); 
		  combination(candidates,list, target,-1, res); 
		  return res;
    }
    public  void combination(int[] candidates, LinkedList<Integer> list, int target,int idx,List<List<Integer>> res) {
		if (target<=0) {
			if (0 == target) {
					res.add(new LinkedList<Integer>(list));
				//target等于0就表明list和等于target，就加入到结果集里面
			}
			return;
		}
		//从idx+1开始是因为每一个只能出现一次，并且可以剪枝，比如2，3，3和3，2，3是一个组合，如果找了3那就不会找2，因为数组排过序，并且下标是从idx开始的
		for (int i =idx+1;i<candidates.length;i++) {
			//第一个剪枝是for循环的剪枝，这也是为了剪枝，不过是递归深度的剪枝，比如（1，1，2，5）如果第一个1加进去，此时第二个1就不会加进去。因为candidates[i]==candidates[i-1]
			if(i>idx+1&&candidates[i]==candidates[i-1]){
                continue;
            }
			list.add(candidates[i]);
			combination(candidates, list, target-candidates[i],i, res);
			list.remove(list.size()-1);
		}
	}
};
```

#### CPP
```C++
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> array;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, array, ret, target, 0);
        return ret;
    }

    void backtrack(vector<int> candidates, vector<int> array, vector<vector<int>>& ret_array, int target, int index)
    {
        if (target == 0)
        {
            ret_array.push_back(array);
            return ;
        }
        else if (target < 0)
        {
            return ;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates[i] <= target)
            {
                if (i > index && candidates[i] == candidates[i - 1])
                    continue;
            }
            array.push_back(candidates[i]);
            backtrack(candidates, array, ret_array, target - candidates[i], i + 1);
            array.pop_back();
        }
    }
};
```