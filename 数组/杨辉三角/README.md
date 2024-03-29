# 杨辉三角

## 题目描述
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

![图示](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

在杨辉三角中，每个数是它左上方和右上方的数的和。

##### 示例:
> 输入: 5
> 输出:
> [
>      [1],
>     [1,1],
>    [1,2,1],
>   [1,3,3,1],
>  [1,4,6,4,1]
> ]


## 解析


## 代码实现
### 方法1：
#### CPP
```C++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if (numRows ==0 )
            return ret;
        ret.push_back(vector(1, 1));
        for (int i = 1; i < numRows; i++)
        {
            vector<int> array(i + 1, 1);
            for (int j = 1; j < array.size() - 1; j++)
            {
                array[j] = ret[i - 1][j - 1] + ret[i - 1][j ];
            }
            ret.push_back(array);
        }
        return ret;
    }
};
```
#### Java
```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        int[][] dp = new int[numRows][numRows];
		dp[0][0]=1;
		List<List<Integer>> res = new LinkedList<>();
		for(int i=0;i<numRows;i++) {
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
            res.add(list);
		}
		return res;
    }
}
```