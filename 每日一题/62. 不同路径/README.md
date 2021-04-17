# 62. 不同路径

## 题目描述
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？


 

### 示例 1：

```
输入：m = 3, n = 7
输出：28
```
### 示例 2：
```
输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
```
### 示例 3：
```
输入：m = 7, n = 3
输出：28
```
### 示例 4：
```
输入：m = 3, n = 3
输出：6
```
### 提示：

 - 1 <= m, n <= 100
 - 题目数据保证答案小于等于 2 * 109

## 解析
 - 动态规划硬刚，花里胡哨的
<table>
<tr>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
<td>1</td>
</tr>
<tr>
<td>1</td>
<td style="background:red;">2</td>
<td>3</td>
<td>4</td>
<td>5</td>
<td style="background:red;">6</td>
<td>7</td>
</tr>
<tr>
<td>1</td>
<td style="background:red;">3</td>
<td>6</td>
<td>10</td>
<td>15</td>
<td>21</td>
<td style="background:red;">28</td>
</tr>
</table>


## 代码实现
```Java
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				if(i==0||j==0) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = dp[i-1][j] +dp[i][j-1];
				}
			}
		}
		return dp[m-1][n-1];
    }
};
```