# 面试题 01.05. 一次编辑

## 题目描述
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

#### 示例 1:
>输入: 
>first = "pale"
>second = "ple"
>输出: True
 
#### 示例 2:
> 输入: 
> first = "pales"
> second = "pal"
> 输出: False

## 解析
### 方法1：
- 首先两个字符串的长度进行比较，如果相差超过1，那么说明一次操作肯定无法完成
- 之后使用两个指针分别指向两个字符串的起始位置
- 遍历字符串判断字符是否相同
- 相同则两个指针向后移动
- 如果不相同，则需要判断两个字符串的长度，如果相等则同时后移，如果不相等，则长的移动，同时需要记录字符不相同出现的次数
- 如果超过了一次，那么则说明不能通过一次编辑来解决

## 代码实现
### 方法1：
#### CPP
```C++
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int len1 = first.length();
        int len2 = second.length();
        if ((len1 - len2 > 1) || (len1 - len2 < -1))
            return false;
        if (first.compare(second) == 0)
            return true;
        int p1 = 0;
        int p2 = 0;
        int count = 0;
        while(p1 < len1 && p2 < len2)
        {
            if (first[p1] == second[p2])
            {
                p1++;
                p2++;
            }
            else
            {
                count++;
                if (count > 1)
                    return false;
                if (len1 > len2)
                    p1++;
                else if (len1 == len2)
                {
                    p1++;
                    p2++;
                }
                else
                    p2++;
            }
        }
        return true;
    }
};
```