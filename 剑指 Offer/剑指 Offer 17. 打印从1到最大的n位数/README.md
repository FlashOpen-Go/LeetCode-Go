# 剑指 Offer 17. 打印从1到最大的n位数

## 题目描述
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。


### 示例 1：
```
输入：n = 1
输出：[1,2,3,4,5,6,7,8,9]
```


说明：
+ 用返回一个整数列表来代替打印
+ n 为正整数




## 代码实现
#### Java
```Java
class Solution {
    public int[] printNumbers(int n) {
        int []  intArr = new int[(int) (Math.pow(10,n)-1)];
		for(int i=0;i<intArr.length;i++) {
			intArr[i] = i+1;
		}
		return intArr;
    }
};
```
#### Python3
```python
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        List = []
        if isinstance(n,int) and n > 0:
            max_num = 10**n
            for i in range(1, max_num):
                List.append(i)
            return List
        else:
            return 'n值不符合要求'
```