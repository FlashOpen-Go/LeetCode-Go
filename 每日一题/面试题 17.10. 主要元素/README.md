# 面试题 17.10. 主要元素

## 题目描述
数组中占比超过一半的元素称之为主要元素。给你一个 整数 数组，找出其中的主要元素。若没有，返回 -1 。请设计时间复杂度为 O(N) 、空间复杂度为 O(1) 的解决方案。

 

### 示例 1：
```
输入：[1,2,5,9,5,9,5,5,5]
输出：5
```
### 示例 2：
```
输入：[3,2]
输出：-1
```
### 示例 3：
```
输入：[2,2,1,1,1,2,2]
输出：2
```



## 代码实现
```Java
class Solution {
    public int majorityElement(int[] nums) {
        //
		int num = 0,count = 0;
		//摩尔投票算法，相同则给数量加一，不同则减一抵消一个
		for(int i=0;i<nums.length;i++) {
			if(count==0) {
				num = nums[i];
			}
			if(num==nums[i]) {
				count++;
			}else {
				count--;
			}
		}
		//校验是否正确
		int cnt=0;
		for(int j=0;j<nums.length;j++) {
			if(num==nums[j]) {
				cnt++;
			}
		}
		return cnt>nums.length/2?num:-1;
    }
};
```