# 15. 三数之和

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

### 示例 1：
```
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
```
### 示例 2：
```
输入：nums = []
输出：[]
```
### 示例 3：
```
输入：nums = [0]
输出：[]
```
 

### 提示：

 - 0 <= nums.length <= 3000
 - -105 <= nums[i] <= 105





## 代码实现
#### Java
```Java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> ret = new ArrayList<>();
        for(int i=0 ;i<n; ++i){
            if(i>0&&nums[i] == nums[i-1]){
                continue;
            }
            int k = n-1;
            int target = -nums[i];
            for(int j=i+1;j<n;++j){
                if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                
                while (j<k&&nums[j]+nums[k]>target){
                    --k;
                }
                
                if(j==k){
                    break;
                }
                
                if(nums[j]+nums[k]==target){
                    List<Integer> list = new ArrayList<>();
                    list.add(nums[i]);
                    list.add(nums[j]);
                    list.add(nums[k]);
                    ret.add(list);
                }
            }
        }
        return ret;
    }
};
```