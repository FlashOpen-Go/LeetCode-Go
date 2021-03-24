# 132 模式

## 题目描述
给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k] 组成，并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j] 。
如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。

进阶：很容易想到时间复杂度为 O(n^2) 的解决方案，你可以设计一个时间复杂度为 O(n logn) 或 O(n) 的解决方案吗？

 

#### 示例 1：
```c
输入：nums = [1,2,3,4]
输出：false
解释：序列中不存在 132 模式的子序列。
```

#### 示例 2：
```c
输入：nums = [3,1,4,2]
输出：true
解释：序列中有 1 个 132 模式的子序列： [1, 4, 2] 。
```

#### 示例 3：
```c
输入：nums = [-1,3,2,0]
输出：true
解释：序列中有 3 个 132 模式的的子序列：[-1, 3, 2]、[-1, 3, 0] 和 [-1, 2, 0] 。
 ```

##### 提示：
```c
n == nums.length
1 <= n <= 104
-109 <= nums[i] <= 109
```

## 解析
#### 方法1：单调栈
- 维护一个单调栈，和一个最大值
- 由于 i < j < k , 并且 nums[i] < nums[k] < nums[j],
- 这样从数组的最后开始查找，更新栈的同时，维护着最大值
- 只要存在一个 nums[i] < max_value，那么一定存在一个 132 模式的数

#### 方法2：单调栈
- 维护一个最小值
- 从数组最后开始遍历，出现大于最小值小于当前值，则存在一个132模式的数


## 代码实现
#### 方法1：单调栈
##### CPP
```C++
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int num_j_value = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] < num_j_value)  return true;
            while(!st.empty() && st.top() < nums[i])
            {
                num_j_value = max(st.top(), num_j_value);
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
```
```Java
class Solution {
    public boolean find132pattern(int[] nums) {
        int len=nums.length;
		int min = nums[0];
		for(int i=0;i<nums.length;i++) {
			min = Math.min(min, nums[i]);//找到最小值
			if(min==nums[i]) {//如果min==nums[i]则当前值等于最小值，跳过
				continue;
			}
			for(int j=len-1;j>i;j--) {
				if(min<nums[j]&&nums[j]<nums[i]) {//若出现132则返回
					return true;
				}
			}
		}
		return false;
    }
};
```