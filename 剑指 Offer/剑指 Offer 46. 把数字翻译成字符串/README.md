# 剑指 Offer 46. 把数字翻译成字符串

## 题目描述
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

 

### 示例 1:
```
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
```
 

### 提示：

 - 0 <= num < 231

## 解析
#### 方法1
- 如果最后一位前一个数时1或者最后一位前一个数时2，且最后一个小于6，那么最后一个可以当一个字母，且最后两个可以当一个字母，设最后一个可以组成的数为dp[i],则dp[i] = dp[i-2]+dp[i-1]
- 以上不符合，则只能最后一位组成一个字母，则dp[i] =dp[i-1]
- 处理好边界情况


## 代码实现
#### 方法1：
#### Java
```Java
class Solution {
    public int translateNum(int num) {
        if(num>=0&&num<10){
            return 1;
        }
        String s = String.valueOf(num);
        int len = s.length();
        int[] dp = new int[len];
        dp[0] = 1;
        if(Integer.parseInt(s.substring(0,1))==1||(Integer.parseInt(s.substring(0,1))==2&&Integer.parseInt(s.substring(1,2))<6)){
            dp[1]=2;
        }else{
            dp[1]=1;
        }
        for(int i=2;i<len;i++){
            if(Integer.parseInt(s.substring(i-1,i))==1||(Integer.parseInt(s.substring(i-1,i))==2&&Integer.parseInt(s.substring(i,i+1))<6)){
                dp[i] = dp[i-1]+dp[i-2];
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp[len-1];
    }
};
```