# 461. 汉明距离

## 题目描述
两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。

### 注意：
 - 0 ≤ x, y < 231.

### 示例:
```
输入: x = 1, y = 4

输出: 2

解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
```

上面的箭头指出了对应二进制位不同的位置。

### 思路：
- 先对两个数进行异或运算，找出所有二进制位不同处
- 异或运算结果和1进行与运算，找出结果为1的个数，也就是二进制位不同的个数





## 代码实现
#### Java
```Java
class Solution {
    public int hammingDistance(int x, int y) {
        //先对x和y进行^操作，判断二进制位是否相同，相同为0，不同则为1
		int z = x^y;
		int sum = 0;
		while(z!=0) {
			//对z和1进行&运算，因为任何数和1进行&运算都会得到这个数，所有这一步会得到1的个数，也就得到了x和y二进制位不同的个数
			sum+=z&1;
			//运算一次右移一个位，直到结束
			z = z>>1;
		}
		return sum;
    }
};
```