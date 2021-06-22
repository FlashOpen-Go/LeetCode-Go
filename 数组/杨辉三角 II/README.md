# 杨辉三角

## 题目描述
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

![图示](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

在杨辉三角中，每个数是它左上方和右上方的数的和。

#### 示例:
> 输入: 3
> 输出: [1,3,3,1]

##### 进阶：
> 你可以优化你的算法到 O(k) 空间复杂度吗？

## 解析


## 代码实现
### 方法1：
#### CPP
```C++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>> ret;
        if (rowIndex ==0 )
            return vector<int>(1, 1);
        ret.push_back(vector(1, 1));
        for (int i = 1; i <= rowIndex; i++)
        {
            vector<int> array(i + 1, 1);
            for (int j = 1; j < array.size() - 1; j++)
            {
                array[j] = ret[i - 1][j - 1] + ret[i - 1][j ];
            }
            ret.push_back(array);
            if (i == rowIndex )
                return array;
        }
        return vector(1, 1);
    }
};
```