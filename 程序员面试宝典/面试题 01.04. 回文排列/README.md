# 面试题 01.04. 回文排列


## 题目描述
给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。
回文串不一定是字典当中的单词。


#### 示例1：
> 输入："tactcoa"
> 输出：true（排列有"tacocat"、"atcocta"，等等）


## 解析
### 方法1：
- 如果是回文序列，那么在对整个字符串进行统计之后字符一定成对出现或单独一个字符
- 因此可以遍历整个字符串，进行统计，如果出现单独两个字符则说明不是回文序列


## 代码实现
### 方法1：
#### CPP
```C++
class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> array(256, 0);
        bool flag = false;
        for (char c : s)
        {
            array[c]++;
        }
        for(int i : array)
        {
            if (i % 2 != 0 && flag == false)
            {
                flag = true;
            }
            else if (i % 2 != 0 && flag)
            {
                return false;
            }
        }
        return true;
    }
};
```