# 剑指 Offer 32 - III. 从上到下打印二叉树 III

## 题目描述
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

 

### 例如:
给定二叉树: [3,9,20,null,null,15,7],
```
    3
   / \
  9  20
    /  \
   15   7
```
返回其层次遍历结果：
```
[
  [3],
  [20,9],
  [15,7]
]
```
 

### 提示：

 - 节点总数 <= 1000



## 解析
#### 方法1：
- 利用双端对流先入先出实现
- 如果是奇数行，那么按照正常顺序假如list，如果是偶数行，那么每次加入第一个位置，方便实现倒序加入

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if (root == null) {
            return ret;
        }

        Deque<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        int flag = 0;
        while (!queue.isEmpty()) {
            flag++;
            List<Integer> level = new ArrayList<Integer>();
            int currentLevelSize = queue.size();
            for (int i = 1; i <= currentLevelSize; ++i) {
                TreeNode node = queue.poll();
                if(flag%2==0){
                    level.add(0, node.val);
                }else{
                    level.add(node.val);
                }
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }

            }
            ret.add(level);
        }

        return ret;
    }
};
```