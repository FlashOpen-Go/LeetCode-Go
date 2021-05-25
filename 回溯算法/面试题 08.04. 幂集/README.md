# 面试题 08.04. 幂集

## 题目描述
幂集。编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。

__说明：__ 解集不能包含重复的子集。

#### 示例:
> 输入： nums = [1,2,3]
> 输出：
> [
>   [3],
>   [1],
>   [2],
>   [1,2,3],
>   [1,3],
>   [2,3],
>   [1,2],
>   []
> ]


## 解析
### 方法1：回溯



## 代码实现
### 方法1：回溯
#### CPP
```C++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp;
        backtrack(ret, nums, 0, temp);
        return ret;

    }
    void backtrack(vector<vector<int>>&array, vector<int> nums, int start, vector<int> List)
    {
        array.push_back(List);
        for (int i = start ; i < nums.size(); i++)
        {
            List.push_back(nums[i]);
            backtrack(array, nums, i+1, List);
            List.pop_back();
        }
    }
};
```

## 更新记录
##### 2021-5-25
- 渡渡鸟添加回溯的CPP实现