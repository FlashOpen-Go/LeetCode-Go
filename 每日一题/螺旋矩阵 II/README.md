
# 螺旋矩阵 II


## 题目描述
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

 

#### 示例 1：
![](spiraln.jpg)
```c
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
```

#### 示例 2：
```c
输入：n = 1
输出：[[1]]
```
 
```
提示：
1 <= n <= 20
```


## 解析
#### 方法1：
- 按照顺序进行添加，遇到边界就变化方向


## 代码实现
### 方法1：
#### CPP
```C++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n);
        for (int i = 0; i < n; i++)
        {
            ret[i].resize(n);
        }
        if (n < 2)
        {
            ret[0][0] = 1;
            return ret;
        }
        int rows = n;
        int cols = n;
        int sum = 1;
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
                ret[top][i] = sum++;
                count--;
            }
            top++;
            // 右侧边缘
            for (int i = top; i  <= down && count >= 1; i++)
            {
                ret[i][right] = sum++;
                count--;
            }
            right--;
            // 下测边缘
            for (int i = right; i >= left && count >= 1; i--)
            {
                ret[down][i] = sum++;
                count--;
            }
            down--;
            // 左侧边缘
            for (int i = down; i >= top && count >= 1; i--)
            {
                ret[i][left] = sum++;
                count--;
            }
            left++;
        }
        return ret;
    }
};
```
```Java
class Solution {
    public int[][] generateMatrix(int n) {
        int num=1;
		int tar = n*n;
		int[][] matrix = new int[n][n];
		int l=0,t=0,r=n-1,b=n-1;
		while(num<=tar) {
			for(int i=l;i<=r;i++) {
				matrix[t][i] = num++;
			}
			t++;
			for(int i=t;i<=b;i++) {
				matrix[i][r] = num++;
			}
			r--;
			for(int i=r;i>=l;i--) {
				matrix[b][i] = num++;
			}
			b--;
			for(int i=b;i>=t;i--) {
				matrix[i][l] = num++;
			}
			l++;
			
		}
		return matrix;
    }
};
```