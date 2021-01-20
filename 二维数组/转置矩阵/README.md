# 转置矩阵

## 题目描述
给定一个矩阵 A， 返回 A 的转置矩阵。
矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
```c
示例 1：
输入：[[1,2,3],[4,5,6],[7,8,9]]
输出：[[1,4,7],[2,5,8],[3,6,9]]

示例 2：
输入：[[1,2,3],[4,5,6]]
输出：[[1,4],[2,5],[3,6]]
 

提示：
1 <= A.length <= 1000
1 <= A[0].length <= 1000
```

## 解析
- 转置实际上是讲数据的原始 行 和 列 进行对调
- new[col][row] = old[row][col]

## 代码
#### CPP
```CPP
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();
        vector<vector<int>> ret(cols, vector<int>(rows, 0));    //创建新的数组
        for (int i = 0; i < rows; i++)                      // 遍历原数组
        {
            for (int j = 0 ; j < cols; j++)
            {   
                ret[j][i] = A[i][j];            // 行列对调
            }
        }
        return ret;
    }
};
```