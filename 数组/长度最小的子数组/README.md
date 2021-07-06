# 长度最小的子数组

## 题目描述
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

#### 示例 1：
> 输入：target = 7, nums = [2,3,1,2,4,3]
>
> 输出：2
>
> 解释：子数组 [4,3] 是该条件下的长度最小的子数组。

#### 示例 2：
> 输入：target = 4, nums = [1,4,4]
>
> 输出：1

#### 示例 3：
> 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
>
> 输出：0
 

#### 提示：
- 1 <= target <= 109
- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105
 

#### 进阶：
- 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。

## 解析
### 方法1：滑动窗
- 使用left 指针和 right 指针，起始时都指向数组开始
- 移动 right 指针，同时计算left 和 right 指针中间所有元素的元素和
- 如果元素和大于 target ，则移动 left 指针，同时计算letf 和 right 指针之间的距离
- 一直移动 left 指针直到到达 right 指针位置或这当前元素和小于 target 时，则再次移动 right 指针

## 代码实现
### 方法1：滑动窗
#### CPP
```C++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int ret = INT_MAX;
        int sum = 0;
        while(right < nums.size())
        {
            sum += nums[right];
            if (sum >= target)
            {
                while( (left <= right) && sum >= target )
                {
                    ret = min( right - left + 1, ret );
                    sum -= nums[left];
                    left++;
                }
            }
            right++;
        }
        return ret == INT_MAX ? 0 : ret;
    }
};
```