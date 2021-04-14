# 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

## 题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

```c
示例：
输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
 
提示：
1 <= nums.length <= 50000
1 <= nums[i] <= 10000
```

## 解析
#### 方法1： 首尾双指针
- 定义两个指针 left 和 right，分别指向数组的开始和结尾，两个指针向中间移动
- 首先 left 指针先找到一个偶数，再由 right 指针找到一个奇数
- 交换两个 left 和 right 指针的数据
- 直到两个指针相遇

## 代码实现
#### CPP
```C++
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int count = nums.size();
        if (count == 1)
            return nums;
        int left = 0;
        int right = count - 1;
        while(left < right)
        {
            while(left < right && (nums[left] % 2 != 0))    // 寻找非奇数
                left++;
            while(left < right && (nums[right] % 2 == 0))   // 寻找非偶数
                right--;
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
        return nums;
    }
};
```
#### Java
```Java
class Solution {
    public int[] exchange(int[] nums) {
        //双指针
		int left=0;
		int right=nums.length-1;
		//遍历条件
		while(left<right) {
			//如果左边是奇数，则跳过，向右移一位
			while(left<right&&nums[left]%2!=0) {
				left++;
			}
			//如果右边是偶数，则跳过，向左移一位
			while(left<right&&nums[right]%2==0) {
				right--;
			}
			//如果左边是偶数，右边是奇数，则兑换位置
			if(left<right) {
				int temp = nums[left];
				nums[left] = nums[right];
				nums[right] = temp;
			}
		}
		return nums;
    }
};
```
#### Python3
```python
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        a, b = [], []
        if not nums: return nums
        for i in nums:
            if i % 2 == 1: a.append(i)
            else: b.append(i)
        return a + b
```