# URL化

## 题目描述
URL化。编写一种方法，将字符串中的空格全部替换为%20。
假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。
（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）

#### 示例 1:
```
输入："Mr John Smith    ", 13
输出："Mr%20John%20Smith"
```
#### 示例 2:
```
输入："               ", 5
输出："%20%20%20%20%20"
```
提示：
- 字符串长度在 [0, 500000] 范围内。

## 代码实现
#### Python3
```python
class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        return S[:length].replace(' ', '%20')   # 输出指定长度位置的字符串
```