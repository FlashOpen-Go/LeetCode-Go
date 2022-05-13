# 剑指 Offer 47. 礼物的最大价值

## 题目描述
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

 

### 示例 1:
```
输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
```
 

### 提示：

 - 0 < grid.length <= 200
 - 0 < grid[0].length <= 200


## 解析
#### 方法1
- 起始点就是数组第一行第一列的数据
- 初始化第一列的数据
- 初始化第一行的数据
- 因为只能向下或者向右，所以最大值一定是上面一个点和左边一个点加上当前点中的一个最大值


## 代码实现
#### 方法1：
#### Java
```Java
class Solution {
    public int maxValue(int[][] grid) {
        int[][] dp = new int[grid.length+1][grid[0].length+1];
        dp[0][0] = grid[0][0];
        for(int i=1;i<grid.length;i++){
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }
        for(int j=1;j<grid[0].length;j++){
            dp[0][j] = dp[0][j-1]+grid[0][j];
        }

        for(int i=1;i<grid.length;i++){
            for(int j=1;j<grid[0].length;j++){
                dp[i][j] = Math.max(dp[i-1][j]+grid[i][j], dp[i][j-1]+grid[i][j]);
            }
        }
        return  dp[grid.length-1][grid[0].length-1];
    }
};
```