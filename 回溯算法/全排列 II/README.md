# 全排列 II


## 题目描述
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

#### 示例 1：
> 输入：nums = [1,1,2]
> 输出：
> [[1,1,2],
>  [1,2,1],
>  [2,1,1]]

#### 示例 2：
> 输入：nums = [1,2,3]
> 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

##### 提示：
> 1 <= nums.length <= 8
> -10 <= nums[i] <= 10


## 解析


## 代码实现
### 方法1：回溯+剪枝
#### CPP
```C++
class Solution {
private:
    vector<bool> m_used;    //记录数据是否被使用
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        m_used.resize(nums.size());
        vector<vector<int>> ret;
        vector<int>array;
        backtrack(ret, nums, array);
        return ret;
    }
    void backtrack(vector<vector<int>>& ret, vector<int>& nums, vector<int>&array)
    {
        if (array.size() == nums.size())
        {
            ret.push_back(array);
        }
        for (int i= 0; i < nums.size(); i++)
        {
            if (m_used[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && m_used[i - 1])
                continue;
            array.push_back(nums[i]);
            m_used[i] = true;
            backtrack(ret, nums, array);
            m_used[i] = false;
            array.pop_back();
        }
    }
};
```