# 剑指 Offer 39. 数组中出现次数超过一半的数字

## 题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

```
示例 1:
输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
 
限制：
1 <= 数组长度 <= 50000
```

## 解析
#### 方法1：
- 分析题目得知，数组非空，并且有一个数字超过了数组长度的一半
- 因此可以对数组进行排序，那么数组的中间位置，一定为众数

## 代码实现
##### 方法1
```C++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return (nums[nums.size() / 2]);
    }
};
```

##### 方法2
```Java
class Solution {
    public int majorityElement(int[] nums) {
        int major = 0,count=0;
		for(int i=0;i<nums.length;i++) {
			if(count==0) {
				major = nums[i];
				count=1;
			}
			else {
				if(major==nums[i]) {
					count++;
				}else {
					count--;
				}
			}
		}
		return major;
    }
}
```
