# 513. 找树左下角的值

## 题目描述
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。

 

### 示例 1:
![例图](https://assets.leetcode.com/uploads/2020/12/14/tree1.jpg)
```
输入: root = [2,1,3]
输出: 1
```
示例 2:
![例图](https://assets.leetcode.com/uploads/2020/12/14/tree2.jpg)
```
输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
```

### 提示:

 - 二叉树的节点个数的范围是 [1,104]
 - -231 <= Node.val <= 231 - 1 

### 解析
1.层序遍历，每一次覆盖list
2因为是从左到右遍历.返回最后一层第一个元素即可


## 代码实现
#### Java
```java
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
    public int findBottomLeftValue(TreeNode root) {
        Deque<TreeNode> deque = new LinkedList<>();
        deque.add(root);
        List<Integer> list = new ArrayList<>();
        while (!deque.isEmpty()){
            int size = deque.size();
            list = new ArrayList<>();
            for(int i=0;i<size;i++){
                TreeNode pop = deque.pop();
                list.add(pop.val);
                if(pop.left!=null){
                    deque.add(pop.left);
                }
                if(pop.right!=null){
                    deque.add(pop.right); 
                }
            }

        }
        return list.get(0);
    }
}
```