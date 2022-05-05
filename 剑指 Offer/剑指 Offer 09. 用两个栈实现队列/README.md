# 剑指 Offer 09. 用两个栈实现队列

## 题目描述
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

### 示例 1：
```
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
```
### 示例 2：
```
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
```
### 提示：

 - 1 <= values <= 10000
 - 最多会对 appendTail、deleteHead 进行 10000 次调用

### 解析
 - inStack存入插入的元素,  outStack存入弹出的元素
 - 如果inStack和outStack都为空，则没有待弹出元素，返回-1
 - 如果outStack无元素，但是inStack有元素，则把inStack元素插入outStack内
 - in2out是把但是inStack有元素内元素转入outStack内



## 代码实现
#### Java
```Java
class CQueue {
    private Deque<Integer> inStack;
	private Deque<Integer>  outStack;

    public CQueue() {
        inStack = new ArrayDeque();
		outStack = new ArrayDeque();
    }
    
    public void appendTail(int value) {
        inStack.push(value);
    }
    
    public int deleteHead() {
        if(outStack.isEmpty()) {
    		if(inStack.isEmpty()) {
    			return -1;
    		}
    		in2out();
    	}
    	
    	return outStack.pop();
    }

    public void in2out() {
    	while(!inStack.isEmpty()) {
    		outStack.push(inStack.pop());
    	}
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.appendTail(value);
 * int param_2 = obj.deleteHead();
 */
```