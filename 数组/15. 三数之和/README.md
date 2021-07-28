# 三数之和

## 题目描述
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。


#### 示例 1：
> 输入：nums = [-1,0,1,2,-1,-4]
> 
> 输出：[[-1,-1,2],[-1,0,1]]

#### 示例 2：
> 输入：nums = []
> 
> 输出：[]

#### 示例 3： 
> 输入：nums = [0]
> 
> 输出：[]
 

#### 提示：
- 0 <= nums.length <= 3000
- -105 <= nums[i] <= 105

## 解析
### 方法1：双指针
- 首先对数组进行排序，之后大循环进行元素遍历，同时需要判断是否出现重复的元素
- 剩下的部分便转化为两数之和的方式进行查找，但是需要查找多个，同时需要对重复的元素进行剔除

## 代码实现
### 方法1：双指针
#### CPP
```C++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3)
            return ret;

        sort(nums.begin(), nums.end());
        if (nums[nums.size() - 1] < 0)
            return ret;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            int left = i + 1;
            int right = nums.size() - 1;

            // 类似于俩个数之和
            while(left < right)
            {
                if (nums[left] + nums[right] > -nums[i])
                {
                    right--;
                }
                else if (nums[left] + nums[right] < -nums[i])
                {
                    left++;
                }
                else
                {
                    ret.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1])
                        left++;
                    while(left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }

        }
        return ret;
    }
};
```