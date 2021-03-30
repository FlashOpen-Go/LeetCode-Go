# 搜索二维矩阵

## 题目描述
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

- 每行中的整数从左到右按升序排列。
- 每行的第一个整数大于前一行的最后一个整数。
 

#### 示例 1：
![](mat.jpg)
```c
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
```

#### 示例 2：
![](mat2.jpg)
```c
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
```
 

##### 提示：
```c
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
```

## 解析
#### 方法1：
- 利用数组的特征进行检索，右上角元素是这一行的最大值同时是这一列的最小值
- 从该位置进行搜索，如果target 大于 当前值，则说明在下一行
- 如果 target 小于 当前值，则说明在左边一列

## 代码实现
#### 方法1
##### CPP
```C++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int i = cols - 1;
        int j = 0;
        while(i >= 0 && j < rows)
        {
            if (matrix[j][i] > target)
            {
                i--;
            }
            else if (matrix[j][i] < target)
            {
                j++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
```