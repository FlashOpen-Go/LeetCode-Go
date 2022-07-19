# 200. 岛屿数量

给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

### 示例 1：
```
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
```
### 示例 2：
```
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
```


### 提示：

 - m == grid.length
 - n == grid[i].length
 - 1 <= m, n <= 300
 - grid[i][j] 的值为 '0' 或 '1'



## 代码实现
#### Java
```Java
class Solution {
    public int numIslands(char[][] grid) {
        int a=grid.length;
        int b = grid[0].length;
        int count = 0;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

    public void dfs(char[][] grid, int  a, int b){
        if(a<0||a>=grid.length||b<0||b>=grid[0].length||grid[a][b]=='0'){
            return;
        }

        grid[a][b] = '0';
        dfs(grid,a-1,b);
        dfs(grid, a, b-1);
        dfs(grid, a+1, b);
        dfs(grid, a,b+1);
    }
};
```