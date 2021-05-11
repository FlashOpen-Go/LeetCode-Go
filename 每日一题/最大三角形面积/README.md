# 最大三角形面积

## 题目描述
给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。

#### 示例 1:
```
输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
输出: 2
解释: 
这五个点如下图所示。组成的橙色三角形是最大的，面积为2。
```
![image](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/04/1027.png)

注意：

- 3 <= points.length <= 50.
- 不存在重复的点。
- -50 <= points[i][j]<= 50.
- 结果误差值在10^-6以内都认为是正确答案。

## 代码实现
#### Python3
```python
from itertools import combinations      # 遍历方法
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        # maxS = abs(x1y2+x2y3+x3y1-x1y3-x2y1-x3y2) / 2
        return max(abs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2) for (x1,y1),(x2,y2),(x3,y3) in combinations(points,3))/2
```