#  雪糕的最大数量

## 题目描述
夏日炎炎，小男孩 Tony 想买一些雪糕消消暑。

商店中新到 n 支雪糕，用长度为 n 的数组 costs 表示雪糕的定价，其中 costs[i] 表示第 i 支雪糕的现金价格。Tony 一共有 coins 现金可以用于消费，他想要买尽可能多的雪糕。

给你价格数组 costs 和现金量 coins ，请你计算并返回 Tony 用 coins 现金能够买到的雪糕的 __最大数量__ 。

__注意__：Tony 可以按任意顺序购买雪糕。


#### 示例 1：
> 输入：costs = [1,3,2,4,1], coins = 7
> 输出：4
> 解释：Tony 可以买下标为 0、1、2、4 的雪糕，总价为 1 + 3 + 2 + 1 = 7

#### 示例 2：
> 输入：costs = [10,6,8,7,7,8], coins = 5
> 输出：0
> 解释：Tony 没有足够的钱买任何一支雪糕。

#### 示例 3：
> 输入：costs = [1,6,3,1,2,5], coins = 20
> 输出：6
> 解释：Tony 可以买下所有的雪糕，总价为 1 + 6 + 3 + 1 + 2 + 5 = 18 。


## 解析
#### 方法1：
- 由于需要买到最大的数量，因此需要尽可能买便宜的
- 首先对数组进行排序，之后计算当前的现金能否买对应的雪糕
- 如果可以则将当前现金减去雪糕的值
- 直到现金不够为止

## 代码实现
### CPP
#### 方法1：
```C++
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ret = 0;
        int sum = 0;
        for (int i = 0; i < costs.size(); i++)
        {
            if (coins >= costs[i])
            {
                coins -= costs[i];
                ret++;
            }
            else
                return ret;
        }
        return ret;
    }
};
```