# 剑指 Offer 30. 包含min函数的栈

## 题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

 

### 示例:
```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
```


### 提示：

 - 各函数的调用总次数不超过 20000 次


### 解析
 - A维护插入的数据栈,  B维护非严格降序的栈
 - 插入的时候，如果插入的数据小于B的栈顶数据，插入B栈
 - 弹出的时候如果A弹出的元素等于B栈栈顶元素，那么弹出的就是最小元素，B栈也应该弹出栈顶元素
 - top获取A栈顶元素，min弹出B栈占顶元素



## 代码实现
#### Java
```Java
class MinStack {

    /** initialize your data structure here. */
	private Stack<Integer> A,B;
	
	
    public MinStack() {
    	A = new Stack<>();
    	B = new Stack<>();
    }
    
    public void push(int x) {
    	A.add(x);
    	if(B.isEmpty()||B.peek()>=x) {
    		B.add(x);
    	}
    }
    
    public void pop() {
    	if(A.pop().equals(B.peek())) {
    		B.pop();
    	}
    	
    }
    
    public int top() {
    	return A.peek();
    }
    
    public int min() {
    	return B.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.min();
 */
```