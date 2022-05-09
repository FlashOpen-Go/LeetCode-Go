# 94. 二叉树的中序遍历

## 题目描述
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

 

### 示例 1：
```
输入：root = [1,null,2,3]
输出：[1,3,2]
```
### 示例 2：
```
输入：root = []
输出：[]
```
### 示例 3：
```
输入：root = [1]
输出：[1]
```


### 提示：

 - 树中节点数目在范围 [0, 100] 内
 - -100 <= Node.val <= 100


进阶: 递归算法很简单，你可以通过迭代算法完成吗？


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
    public List<Integer> inorderTraversal(TreeNode root) {
        if(root==null){
            return new ArrayList<>();
        }
        List<Integer> list = getList(root, new ArrayList<>());
        return list;
    }

    public List<Integer> getList(TreeNode treeNode, List<Integer> list){
        if(treeNode==null){
            return null;
        }
        getList(treeNode.left, list);
        list.add(treeNode.val);
        getList(treeNode.right, list);
        return list;
    }
};
```