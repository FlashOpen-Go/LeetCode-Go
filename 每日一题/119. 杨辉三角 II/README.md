# 119. 杨辉三角 II

## 题目描述
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

 

### 示例:
```
输入: 3
输出: [1,3,3,1]
```
### 进阶：

 - 你可以优化你的算法到 O(k) 空间复杂度吗？



## 代码实现
```Java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        int[][] dp = new int[34][34];
		dp[0][0]=1;
		for(int i=0;i<=33;i++) {
			List<Integer> list = new LinkedList<Integer>();
			for(int j=0;j<=i;j++) {
				if(j==0||j==i) {
					dp[i][j] = 1;
				}else {
					dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
				}
				if(dp[i][j]!=0) {
					list.add(dp[i][j]);
				}
			}
			if(i==rowIndex){
                return list;
            }
		}
		return null;
    }
};
```