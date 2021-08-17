# 64. 最小路径和

## 题目描述
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

**说明**：每次只能向下或者向右移动一步。


### 示例 1：

<img src="https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg" alt>
```

   输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
   输出：7
   解释：因为路径 1→3→1→1→1 的总和最小。
```
示例 2：
```
   输入：grid = [[1,2,3],[4,5,6]]
   输出：12
```


### 提示：
 - m == grid.length
 - n == grid[i].length
 - 1 <= m, n <= 200
 - 0 <= grid[i][j] <= 100




## 代码实现
#### Java
```Java
class Solution {
    public int minPathSum(int[][] grid) {
        int[][] dp = new int[grid.length][grid[0].length];
		dp[0][0] = grid[0][0];
		for(int i=0;i<grid.length;i++) {
			for(int j=0;j<grid[i].length;j++) {
				if(!(i==0&&j==0)){
                    if(i==0) {
					dp[i][j] = dp[i][j-1]+grid[i][j];
                    }else if(j==0) {
                        dp[i][j] = dp[i-1][j]+grid[i][j];
                    }else {
                        dp[i][j] = Math.min(dp[i][j-1], dp[i-1][j])+grid[i][j];
                    }
                }
			}
		}
		return dp[grid.length-1][grid[0].length-1];
    }
};
```