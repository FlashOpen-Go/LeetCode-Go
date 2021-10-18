# 74. 搜索二维矩阵

## 题目描述
编写一个高效的算法来判断m*n矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 - 每行中的整数从左到右按升序排列。
 - 每行的第一个整数大于前一行的最后一个整数。

#### 示例 1:
![image](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)
```
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
```
#### 示例 2:
![image](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/11/25/mat2.jpg)
```
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
```

提示：

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 100
- -104 <= matrix[i][j], target <= 104

## 代码实现
#### Python3
```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        M, N = len(matrix), len(matrix[0])
        column0 = [row[0] for row in matrix]
        target_row = bisect.bisect_right(column0, target) - 1
        if target_row < 0:
            return False
        target_col = bisect.bisect_left(matrix[target_row], target)
        if target_col >= N:
            return False
        if matrix[target_row][target_col] == target:
            return True
        return False
```
#### 解析
 - 先找到 matrix[i][0] 小于 target 并且 matrix[i + 1][0] > target 的第 i 行
 - 然后在该行内进行二分找到 target