# 面试题 10.01. 合并排序的数组

## 题目描述
给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

#### 示例:
> 输入:
> A = [1,2,3,0,0,0], m = 3
> B = [2,5,6],       n = 3
> 输出: [1,2,2,3,5,6]

#### 说明:
- A.length == n + m


## 解析
### 方法1：双指针
- 由于A和B都是已经排序好的数组，因此只需比较两个数的值，将大的数方法数组中即可
- A的尾部有空余的空间 ，再合并时不能覆盖的A前面的数值，因此可以反向遍历两个数组，将最大值放到数组结尾
- 使用两个指针分别指向两个数组最后的一个有效位置，之后判断两个数的大小，将其放到A的末尾


## 代码实现
### 方法1：双指针
#### CPP
```C++
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int A_Right = m - 1;
        int B_Right = n - 1;
        int count = A.size() - 1;
        while(count >= 0 && A_Right >=0 && B_Right >= 0)
        {
            if (A[A_Right] >= B[B_Right])
            {
                A[count] = A[A_Right];
                A_Right--;
            }
            else
            {
                A[count] = B[B_Right];
                B_Right--;
            }
            count--;
        }
        while (count >= 0 && B_Right >= 0)
        {
            A[count] = B[B_Right];
            B_Right--;
            count--;
        }
    }
};
```


## 更新记录
##### 2021-5-21
- 渡渡鸟添加双指针解析和CPP的实现