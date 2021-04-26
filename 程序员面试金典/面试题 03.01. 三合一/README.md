# 面试题 03.01. 三合一

## 题目描述
三合一。描述如何只用一个数组来实现三个栈。

你应该实现push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。stackNum表示栈下标，value表示压入的值。

构造函数会传入一个stackSize参数，代表每个栈的大小。

#### 示例1:
> __输入：__
> ["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
> [[1], [0, 1], [0, 2], [0], [0], [0], [0]]
> __输出：__
> [null, null, null, 1, -1, -1, true]
> __说明：__ 当栈为空时`pop, peek`返回-1，当栈满时`push`不压入元素。

#### 示例2:
> __输入：__
> ["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
> [[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]
> __输出：__
> [null, null, null, null, 2, 1, -1, -1]

## 解析


## 代码实现
### 方法1：二维数组
#### CPP
```C++
class TripleInOne {
public:
    vector<vector<int>> m_array;
    vector<int> m_stackPoint;
    int m_StackSize;
    TripleInOne(int stackSize) {
        m_stackPoint = vector<int>(3, -1);
        m_array = vector<vector<int>>(3, vector<int>(stackSize));
        m_StackSize = stackSize;
    }
    
    void push(int stackNum, int value) {
        if(m_stackPoint[stackNum]+1 == m_StackSize)   
            return;
        m_stackPoint[stackNum] += 1;
        m_array[stackNum][m_stackPoint[stackNum]] = value;
    }
    
    int pop(int stackNum) {
        if (m_stackPoint[stackNum] == -1)
            return -1;
        m_stackPoint[stackNum]--;
        return  m_array[stackNum][m_stackPoint[stackNum] + 1];
    }
    
    int peek(int stackNum) {
        if (m_stackPoint[stackNum] == -1)
            return -1;
        return  m_array[stackNum][m_stackPoint[stackNum]];
    }
    
    bool isEmpty(int stackNum) {
        return m_stackPoint[stackNum] == -1;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
```