# 3. 无重复字符的最长子串

## 题目描述
给你一个字符串 s，找到 s 中最长的回文子串。

 

### 示例 1:
```
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```
### 示例 2:
```
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```
### 示例 3:
```
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```
### 示例 4:
```
输入: s = ""
输出: 0
```

### 提示：

 - 0 <= s.length <= 5 * 104
 - s 由英文字母、数字、符号和空格组成

### 解析
 - 滑动窗口，初始化一个i和j
 - 当出现重复时，i右移，否则j右移，直到j滑动到数组边界为止，返回最大值





## 代码实现
```Java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int i=0,j=1,count=0;
		//初始化起始位和终止位，如果出现重复则i右移一位，否则，j右移一位，记住最长长度，知道j滑动到字符串的最右边
		while(j<=s.length()) {
			//如果未出现重复，j右移
			if(i==j-1||s.substring(i, j).indexOf(s.charAt(j-1))==j-i-1) {
				j++;
			//如果出现重复，记住最大值，同时i右移
			}else {
				count = Math.max(count, j-i-1);
				i++;
			}
		}
		return Math.max(count, j-i-1);
    }
};
```
```C++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = INT_MIN;
        if (s.length() < 2)
            return s.length();
        int left = 0;
        int right = 1;
        unordered_set<char> set;
        set.insert(s[left]);
        while(right < s.length())
        {
            if (set.count(s[right]) > 0)
            {
                ret = max( right - left, ret);
                // cout << ret << endl;
                while(right >= left && set.count(s[right]) > 0)
                {
                    set.erase(s[left++]);
                }
            }
            set.insert(s[right]);
            right++;
        }
        ret = max( right - left, ret);
        return ret == INT_MIN ? 0 : ret;
    }
};
```