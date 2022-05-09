# 101. 对称二叉树

## 题目描述
给你一个二叉树的根节点 root ， 检查它是否轴对称。

 

### 示例 1：
![图解](https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg)
```
输入：root = [1,2,2,3,4,4,3]
输出：true
```
### 示例 2：
![图解](https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg)
```
输入：root = [1,2,2,null,3,null,3]
输出：false
```


### 提示：

 - 树中节点数目在范围 [1, 1000] 内
 - -100 <= Node.val <= 100


进阶：你可以运用递归和迭代两种方法解决这个问题吗？




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
    public boolean isSymmetric(TreeNode root) {
        Stack<TreeNode> left = new Stack<>();
        left.push(root.left);
        List<Integer> list = new ArrayList<>();
        Stack<TreeNode> right = new Stack<>();
        right.push(root.right);
        List<Integer> rist = new ArrayList<>();
        while(!left.isEmpty()){
            TreeNode lop = left.pop();
            if(lop==null){
                list.add(0);
                continue;
            }
            list.add(lop.val);
            //if(lop.left!=null){
                left.push(lop.left);
            //}
            //if(lop.right!=null){
                left.push(lop.right);
            //}
        }
        while(!right.isEmpty()){
            TreeNode lop = right.pop();
            if(lop==null){
                rist.add(0);
                continue;
            }
            rist.add(lop.val);
            //if(lop.right!=null){
                right.push(lop.right);
            //}
            //if(lop.left!=null){
                right.push(lop.left);
            //}
        }
        if(list.size()!=rist.size()){
            return false;
        }
        for(int i=0;i<list.size();i++){
            if(list.get(i)!=rist.get(i)){
                return false;
            }
        }
        return true;

    }
};
```