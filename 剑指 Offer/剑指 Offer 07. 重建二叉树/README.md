# 剑指 Offer 07. 重建二叉树

## 题目描述
输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

### 示例 1:
![图解](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)
```
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
```
### 示例 2:
```
Input: preorder = [-1], inorder = [-1]
Output: [-1]
```
 

### 限制：

 - 0 <= 节点个数 <= 5000
### 解析
 - 先设置当前节点，然后切割数组传给后续左右子树，依次递归

## 代码实现
#### Java
```Java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        TreeNode treeNode = new TreeNode();
        if(preorder.length==0){
            return null;
        }
        treeNode.val = preorder[0];
        for(int i=0;i<inorder.length;i++){
            if(inorder[i] == preorder[0]){
                treeNode.right = buildTree(Arrays.copyOfRange(preorder,i+1,preorder.length),Arrays.copyOfRange(inorder,i+1,inorder.length));
                treeNode.left = buildTree(Arrays.copyOfRange(preorder,1,i+1),Arrays.copyOfRange(inorder,0,i));
            }
        }
        return treeNode;
    }
};
```