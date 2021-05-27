# 面试题 01.01. 判定字符是否唯一

## 题目描述
实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

#### 示例 1：
> 输入: s = "leetcode"
> 输出: false 

#### 示例 2：
> 输入: s = "abc"
> 输出: true

#### 限制：
> 0 <= len(s) <= 100
> 如果你不使用额外的数据结构，会很加分。


## 解析
### 方法1：位运算
使用一个int类型的值来进行标记，每一个bit表示一个字母，遍历字符串判断对应bit是否为1
### 方法2：判断出现位置
判断当前元素第一次出现的位置是不是当前位置，如果是就出现一次，否则不止一次

## 代码实现
### 方法1：位运算
#### CPP
```C++
class Solution {
public:
    bool isUnique(string astr) {
        int bit = 0;
        for (char c : astr)
        {
            int move = int(c) - int('a');
            cout << move << endl;
            if ((bit & (1 << move)))
                return false;
            else
                bit |= (1 << move);
        }
        return true;
    }
};
```
### 方法2：判断当前元素第一次出现的位置是不是当前位置
#### Java
```Java
class Solution {
    public boolean isUnique(String astr) {
        for(int i=0;i<astr.length();i++) {
			if(i!=astr.indexOf(astr.charAt(i))) {
				return false;
			}
		}
		return true;
    }
};
```
#### Python3
```python
class Solution:
    def isUnique(self, astr: str) -> bool:
        return len(set(astr)) == len(astr)
```