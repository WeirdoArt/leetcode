class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= target) {
                return i;
            }
        }
        return nums.size();
    }
};
/**
解题思路：
    面试中如果这么简单的实现，估计面试官不会很满意，其实面试官是想考一些有难度的算法吧
 */

// 二分查找
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.back() < target) {
            return nums.size();
        }
        
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return right;
    }
};
/**
解题思路：
    最简单的二分查找法，链表中也经常会用到，核心就是不断缩小边界（left或right），同时计算新的mid，需要注意的是下标从0开始的因素要考虑到
 */
