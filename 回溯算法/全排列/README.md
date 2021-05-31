# 全排列

## 题目描述
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

#### 示例 1：
> 输入：nums = [1,2,3]
> 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

#### 示例 2：
> 输入：nums = [0,1]
> 输出：[[0,1],[1,0]]

#### 示例 3：
> 输入：nums = [1]
> 输出：[[1]]
 

##### 提示：
> 1 <= nums.length <= 6
> -10 <= nums[i] <= 10
> nums 中的所有整数 互不相同

## 解析
### 方法1：回说

## 实现
### 方法1：回说
#### CPP
```C++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> array;
        backtrack(ret, nums, 0);
        return ret;
    }
    void backtrack(vector<vector<int>>& ret, vector<int>nums, int index)
    {
        if (index == nums.size())
        {
            ret.push_back(nums);
            return;
        }
        for ( int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            backtrack(ret, nums,  index + 1);
            swap(nums[i], nums[index]);
        }
    }
};
```