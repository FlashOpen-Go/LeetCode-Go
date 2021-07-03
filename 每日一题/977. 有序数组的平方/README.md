# 977. 有序数组的平方

## 题目描述
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

 

### 示例 1：
```
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
```
### 示例 2：
```
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
```
 

### 提示：

 - 1 <= nums.length <= 104
 - -104 <= nums[i] <= 104
 - nums 已按 非递减顺序 排序
 

### 进阶：

 - 请你设计时间复杂度为 O(n) 的算法解决本问题


## 解析
- 初始化左右两个指针，新建一个返回的数组
- 判断左边和有百年谁大，
- 如果左边大，把当前值平方存入新建数组的最大下标处，下标减一，并且左边右移
- 如果右边大，把当前值平方存入新建数组下标最大值，下标减一，右边左移



## 代码实现
```Java
class Solution {
    public int[] sortedSquares(int[] nums) {
        //定义左右两个下标
		int left = 0,right = nums.length-1;
		int[] retArr = new int[nums.length];
		int k = nums.length-1;
		while(left<=right) {
			//如果左边绝对值大于右边，那么平方一定大于右边，这时候他是最大的，左边右移，新数组下标减一
			if(Math.abs(nums[left])>Math.abs(nums[right])) {
				retArr[k] = nums[left]*nums[left];
				left++;
				k--;
			}else {//反之，那么平方一定小于于右边，这时候右边是最大的，右边左移，新数组下标减一
				retArr[k] = nums[right]*nums[right];
				right--;
				k--;
			}
		}
		return retArr;
    }
};
```