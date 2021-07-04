# 283. 移动零

## 题目描述
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

### 示例:
```
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
```
### 说明:

 - 必须在原数组上操作，不能拷贝额外的数组。
 - 尽量减少操作次数。


## 解析
- 把非0的数移到前面来
- 把后面数据重置为0



## 代码实现
```Java
class Solution {
    public void moveZeroes(int[] nums) {
        int j=0;
		//赋值为非0的数
		for(int i=0;i<nums.length;i++) {
			if(nums[i]!=0) {
				nums[j++] = nums[i];
			}
		}
		//赋值为0
		while(j<nums.length) {
			nums[j++] = 0;
		}
    }
};
```