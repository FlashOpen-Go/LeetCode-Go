# 剑指 Offer 63. 股票的最大利润

## 题目描述
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

### 示例 1：
```
输入：[7,1,5,3,6,4]
输出：5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
```
### 示例 2：
```
输入：[7,6,4,3,1]
输出：0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
```

### 限制：
0 <= 数组长度 <= 10^5


## 解析
#### 方法1：
- 实际上只需要找到数组中的两个峰值，即最小值和最大值即可。
- 遍历数组，维护一个最小值，当遍历的元素小于最小值时更新最小值，否则则用当前的数值减去最小值

## 代码实现
#### Java
```Java
class Solution {
    public int maxProfit(int[] prices) {
       if(prices == null || prices.length <= 1) {
            return 0;
        }
        int res = 0, min = prices[0];
        for(int i = 1; i < prices.length; i++) {
			//取代最小值
            if(prices[i] <= min) {
                min = prices[i];
            }else {
			//如果不是最小值，那么与最小值相减再和相减最大值比大小，返回最大的值
                res = Math.max(res, prices[i] - min);
            }
        }
        return res;
    }
};
```

#### CPP
```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue = (numeric_limits<int>::max)();
        int ret = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (minValue > prices[i])
            {
                minValue = prices[i];
            }
            else
            {
                ret = max(ret, prices[i] - minValue);
            }
        }
        return ret;
    }
};
```