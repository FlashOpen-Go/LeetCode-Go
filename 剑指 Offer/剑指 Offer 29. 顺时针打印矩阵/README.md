# 剑指 Offer 29. 顺时针打印矩阵

## 题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 
#### 示例 1：
```c
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
```

#### 示例 2：
```c
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
```

```c
限制：
0 <= matrix.length <= 100
0 <= matrix[i].length <= 100
```

## 解析
#### 方法1：
- 按照顺序进行遍历，遇到边界就变化方向，直到数组结束


## 代码实现
#### 方法1
- CPP
```C++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int rows = matrix.size();
        if (rows < 1)
            return ret;
        int cols = matrix[0].size();
        int count = rows * cols;
        int left = 0;           // 横向左边界
        int right = cols - 1;   // 横向右边界
        int top = 0;            // 纵向上边界
        int down = rows - 1;    // 纵向下边界
        while(count >= 1)
        {
            // 上方边缘遍历
            for (int i = left; i  <= right && count >= 1; i++) 
            {
                ret.push_back(matrix[top][i]);
                count--;
            }
            top++;
            // 右侧边缘
            for (int i = top; i  <= down && count >= 1; i++)
            {
                ret.push_back(matrix[i][right]);
                count--;
            }
            right--;
            // 下测边缘
            for (int i = right; i >= left && count >= 1; i--)
            {
                ret.push_back(matrix[down][i]);
                count--;
            }
            down--;
            // 左侧边缘
            for (int i = down; i >= top && count >= 1; i--)
            {
                ret.push_back(matrix[i][left]);
                count--;
            }
            left++;
        }
        return ret;
        
    }
};
```