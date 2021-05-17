# 面试题 01.02. 判定是否互为字符重排

## 题目描述
给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

#### 示例 1：
> 输入: s1 = "abc", s2 = "bca"
> 输出: true 

#### 示例 2：
> 输入: s1 = "abc", s2 = "bad"
> 输出: false

#### 说明：
> 0 <= len(s1) <= 100
> 0 <= len(s2) <= 100


## 解析
### 方法1：
- 使用一个数组来记录S1中每一个元素出现的次数
- 之后再遍历S2，对应字符位置自减，如果不出现小于0，则说明相同
### 方法2：
- 给两个字符串的字符数组排序，然后比较，不同返回false，否则返回true

## 代码实现
### 方法1：
#### CPP
```C++
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        vector<int> array(26, 0);
        for (char c : s1)
            array[(c - 'a')]++;
        for (char c : s2)
        {
            array[(c - 'a')]--;
            if (array[(c - 'a')] < 0)
                return false;
        }
        return true;
    }
};
```
### 方法2：
#### Java
```Java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if(s1.length()!=s2.length()) {
			return false;
		}
		char[] charArray = s1.toCharArray();
		char[] charArray2 = s2.toCharArray();
		Arrays.parallelSort(charArray);
		Arrays.parallelSort(charArray2);
		for(int i=0;i<charArray.length;i++) {
			if(charArray[i]!=charArray2[i]) {
				return false;
			}
		}
		return true;
    }
};
```