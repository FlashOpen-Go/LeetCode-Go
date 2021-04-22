# 11. 盛最多水的容器

## 题目描述

给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。

 

### 示例 1：

<img src="https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg">
```
输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
```
### 示例 2：
```
输入：height = [1,1]
输出：1
```
### 示例 3：
```
输入：height = [4,3,2,1,4]
输出：16
```
### 示例 4：
```
输入：height = [1,2,1]
输出：2
```

### 提示：

 - n = height.length
 - 2 <= n <= 3 * 104
 - 0 <= height[i] <= 3 * 104




## 代码实现
```Java
class Solution {
    public int maxArea(int[] height) {
        int res = 0;
		int i=0,j=height.length-1;
		while(i<j) {
            //取height[i]和height[j]当前较小的一个数乘以i和j间的距离，就是当前i和j能容纳最多的水，然后和历史最大比取大的值
			res = Math.max(res, Math.min(height[i], height[j])*(j-i));
            //如果height[i]<height[j]，那么i后面的任何数都不会比j大，此时i+1
			if(height[i]<height[j]) {
				i++;
                //否则j-1
			}else {
				j--;
			}
		}
		return res;
    }
};
```