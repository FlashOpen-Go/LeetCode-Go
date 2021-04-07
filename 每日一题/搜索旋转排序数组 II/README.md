# 搜索旋转排序数组 II

## 题目描述
已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。

给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。

 

#### 示例 1：
```C
输入：nums = [2,5,6,0,0,1,2], target = 0
输出：true
```

#### 示例 2：
```C
输入：nums = [2,5,6,0,0,1,2], target = 3
输出：false
```

##### 提示：
> 1 <= nums.length <= 5000
> -104 <= nums[i] <= 104
> 题目数据保证 nums 在预先未知的某个下标上进行了旋转
> -104 <= target <= 104
 

##### 进阶：
> 这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
> 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

## 解析
### 方法1：二分查找
- 由于数组整体式升序的，但是被旋转了一次，因此二分查找时可能会出现区间无法判断的问题，这就是left和right以及mid的值相同时，这时只能对left加一，right减一操作
- 如果相等，则需要使用mid和left的值进行判断，判断段左侧区间是否有序

## 代码实现
### 方法1：二分查找
#### CPP
```C++
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return false;
        if (nums.size() == 1)
            return (nums[0] == target);
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            // 无法判断区间
            if (nums[mid] == nums[left] && nums[mid] == nums[right])
            {
                left++;
                right--;
            }
            else if (nums[mid] >= nums[left]) 
            {
                // 左侧区间是升序的，判断target是否在这个区间内
                if ((nums[left] <= target) && (target < nums[mid]))
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else // 
            {
                // 
                if ((nums[nums.size() - 1] >= target) && (target > nums[mid]))
                {
                    left = mid + 1;
                }
                else 
                {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
```