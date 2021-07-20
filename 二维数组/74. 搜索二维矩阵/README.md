# 74. 搜索二维矩阵

## 题目描述
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
 

### 示例 1：
<img src="https://assets.leetcode.com/uploads/2020/10/05/mat.jpg" alt>
```
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
```
### 示例 2：
<img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/11/25/mat2.jpg" alt>
```
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
```
 

### 提示：

 - m == matrix.length
 - n == matrix[i].length
 - 1 <= m, n <= 100
 - -104 <= matrix[i][j], target <= 104

### 解析
 - 先取第一行最后一个，然后慢慢逼近

## 代码
### Java
```Java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int r=0,c=matrix[0].length-1;
		while(r<=matrix.length-1&&c>=0) {
			if(matrix[r][c]>target) {
				c--;
			}else if(matrix[r][c]<target){
				r++;
			}else {
				return true;
			}
		}
		return false;
    }
};
```