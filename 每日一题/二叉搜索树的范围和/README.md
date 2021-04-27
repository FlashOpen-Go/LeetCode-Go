# 938. 二叉搜索树的范围和

## 题目描述
给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。

 

### 示例 1：
<img src="https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg">
```
输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
输出：32
```
### 示例 2：
<img src="https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg">
```
输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
输出：23
``` 

### 提示：

 - 树中节点数目在范围 [1, 2 * 104] 内
 - 1 <= Node.val <= 105
 - 1 <= low <= high <= 105
 - 所有 Node.val 互不相同

### 解析
 - 中序遍歷整個樹，如果值在low和high之間，就加上，返回sum




## 代码实现
```Java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int rangeSumBST(TreeNode root, int low, int high) {
    	if(root==null) return 0;
    	Queue<TreeNode> queue =new  LinkedList<TreeNode>();
    	queue.add(root);
    	int sum=0;
    	while(!queue.isEmpty()) {
    		//彈出隊列頂部再把彈出的左右子樹加進去直到左右爲空爲止
    		TreeNode poll = queue.poll();
    		//如果在low和high之間，就加上
    		if(poll.val>=low&&poll.val<=high) {
    			sum+=poll.val;
    		}
			//如果左子樹不爲空，add進去，同理，如果右子樹不爲空，add進去
    		if(poll.left!=null) {
    			queue.add(poll.left);
    		}
    		if(poll.right!=null) {
    			queue.add(poll.right);
    		}
    	}
        return sum;
    }turn sum;
    }
};
```