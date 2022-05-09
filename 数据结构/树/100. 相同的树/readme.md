# 94. 二叉树的中序遍历

## 题目描述
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

 

### 示例 1：
![图解](https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg)
```
输入：p = [1,2,3], q = [1,2,3]
输出：true
```
### 示例 2：
![图解](https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg)
```
输入：p = [1,2], q = [1,null,2]
输出：false
```
### 示例 3：
![图解](https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg)
```
输入：p = [1,2,1], q = [1,1,2]
输出：false
```


### 提示：

 - 两棵树上的节点数目都在范围 [0, 100] 内
 - -104 <= Node.val <= 104



## 实现
### Java
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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p==null&&q==null){
            return true;
        }
        if(p==null||q==null){
            return false;
        }
        if(p.val!=q.val){
            return false;
        }
       // if(p.left!=null&&q.left!=null){
          boolean a=  isSameTree(p.left,q.left);
       // }
       // if(p.right!=null&&q.right!=null){
           boolean b = isSameTree(p.right, q.right);
        //}
        
        return a&&b;
    }
};
```