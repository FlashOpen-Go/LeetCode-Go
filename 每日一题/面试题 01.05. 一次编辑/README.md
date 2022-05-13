# 面试题 01.05. 一次编辑


## 题目描述
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

 

### 示例 1:
```
输入: 
first = "pale"
second = "ple"
输出: True
```
 

### 示例 2:
```
输入: 
first = "pales"
second = "pal"
输出: False
```


## 解析
- 如果长度相等，判断不一样的字符个数，大于1返回false，否则返回true
- 如果长度不相等，则遍历短的，不相等时给偏移量加1，等遍历结束，判断不相等个数，如果大于1返回false，否则返回true



## 代码实现
```Java
class Solution {
    public boolean oneEditAway(String first, String second) {
        int lf = first.length();
        int ls = second.length();
        if(ls-lf>1){
            return false;
        }
        if(ls<lf){
            return oneEditAway(second,first);
        }
        if(ls==lf){
            int count=0;
            for(int i=0;i<ls;i++){
                if(first.charAt(i)!=second.charAt(i)){
                    count++;
                }
            }
            return count<=1;
        }
        int index = 0, offset = 0;
        /* 4. 两者长度相差 1 执行插入操作 */
        while (index < lf) {
            /* 两者不相等时让长的那个往后偏移 offset 此变量也是需要删除字符的个数 */
            if (first.charAt(index) != second.charAt(index+offset)) {
                if (++offset > 1) return false; // 若同字符个数大于1 直接返回false
                /* 两者相等直接比较下一个 */
            } else index += 1;
        }
        return true;
    }
};
```