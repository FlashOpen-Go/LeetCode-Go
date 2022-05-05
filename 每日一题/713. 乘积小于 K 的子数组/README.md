# 713. 乘积小于 K 的子数组

## 题目描述
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。


### 示例 1：
```
输入：nums = [10,5,2,6], k = 100
输出：8
解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
```
### 示例 2：
```
输入：nums = [1,2,3], k = 0
输出：0
```


### 提示: 

 - 1 <= nums.length <= 3 * 104
 - 1 <= nums[i] <= 1000
 - 0 <= k <= 106


## 解析
- 先找出单个小于k的数，加入结果集
- 快慢指针，如果结果小于k就加1，并且右指针右移
- 如果右指针到了最右了，那么左指针加一，并且右指针从左指针右1位开始
- 如果结果大于k，那么左指针加一，并且右指针从左指针右1位开始



## 代码实现
```Java
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
     int len = nums.length;
     int left=0,right=1;
     int sum = nums[0];
     int count = 0;
     for(int i=0;i<nums.length;i++) {
    	 if(nums[i]<k) {
    		 count++;
    	 }
     }
     while (left<len-1&&right<len){
         sum = sum*nums[right];
         if(sum<k){
             count++;
             right++;
             if(right==len) {
            	 left++;
                 sum = nums[left];
                 right = left+1;
             }
         }else{
             left++;
             sum = nums[left];
             right = left+1;
         }

     }
     return count;
    }
};
```