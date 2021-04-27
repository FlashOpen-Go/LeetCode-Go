# 633. 平方数之和

## 题目描述
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。

 

### 示例 1：
```
输入：c = 5
输出：true
解释：1 * 1 + 2 * 2 = 5
```
### 示例 2：
```
输入：c = 3
输出：false
```
### 示例 3：
```
输入：c = 4
输出：true
```
### 示例 4：
```
输入：c = 2
输出：true
```
### 示例 5：
```
输入：c = 1
输出：true
```

### 提示：

 - 0 <= c <= 231 - 1

### 解析
 - 求出a和b的最小值以及最大值，然后双指针救出a和b的值



## 代码实现
```Java
class Solution {
    public boolean judgeSquareSum(int c) {
        int left = 0;
		int right = (int) Math.floor(Math.sqrt(c));
		while(left<right) {
			if(left*left+right*right>c) {
				right--;
			}else if(left*left+right*right<c){
				left++;
			}
			else {
				return true;
			}
		}
		return false;
    }
};
```