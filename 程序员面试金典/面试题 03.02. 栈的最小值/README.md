# 面试题 03.02. 栈的最小值

## 题目描述
请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。


#### 示例：
> MinStack minStack = new MinStack();
> minStack.push(-2);
> minStack.push(0);
> minStack.push(-3);
> minStack.getMin();   --> 返回 -3.
> minStack.pop();
> minStack.top();      --> 返回 0.
> minStack.getMin();   --> 返回 -2.

## 解析
### 方法1：双栈记录
- 使用两个栈俩记录数据，一个栈用来记录压入的数据，另一个栈记录压入元素时的最小值
- 当有元素入栈时，判断最小值栈的栈顶元素和入栈元素的大小关系，将小值入栈
- 最小值栈保证了当前情况下的最小值

## 代码实现
### 方法1：双栈记录
#### CPP
```C++
class MinStack {
public:
    stack<int> m_stack;
    stack<int> m_min_stack;
    /** initialize your data structure here. */
    MinStack() {
        m_min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        m_stack.push(x);
        m_min_stack.push(min(m_min_stack.top(), x));
    }
    
    void pop() {
        m_stack.pop();
        m_min_stack.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```