#  二进制手表

## 题目描述
二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。每个 LED 代表一个 0 或 1，最低位在右侧。

例如，下面的二进制手表读取 "3:25" 。
![tu](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/03/29/binary_clock_samui_moon.jpg)

给你一个整数 turnedOn ，表示当前亮着的 LED 的数量，返回二进制手表可以表示的所有可能时间。你可以 __按任意顺序__ 返回答案。

小时不会以零开头：
- 例如，"01:00" 是无效的时间，正确的写法应该是 "1:00" 。

分钟必须由两位数组成，可能会以零开头：
- 例如，"10:2" 是无效的时间，正确的写法应该是 "10:02" 。

#### 示例 1：
>输入：turnedOn = 1
>输出：["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

#### 示例 2：
> 输入：turnedOn = 9
> 输出：[]
 

##### 提示：
> 0 <= turnedOn <= 10

## 解析
### 方法1：暴力破解
- 使用10个bit来表示，高四位为小时，低六位为分钟
- 10个bit总共有1024种可能
- 遍历这1024中可能，统计其中1出现的次数，符合条件的则添加到返回数组中

## 代码实现
### 方法1：暴力破解
#### CPP
```C++
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ret;
        for (int i = 0; i < 1024; i++)
        {
            int h = i >> 6;
            int f = i & 0x3F;
            if ( h < 12 && f < 60 && __builtin_popcount(i) == turnedOn)
            {
                ret.push_back( to_string(h) + ":" + (f < 10 ? "0" : "") + to_string(f) );
            }
        }
        return ret;
    }
};
```