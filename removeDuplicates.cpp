// Approach 1: Two Pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        for (auto iter = nums.begin(); iter + 1 != nums.end(); ++iter) {
            if (*iter == *(iter + 1)) {
                nums.erase(iter--);
            }
        }
        return nums.size();
    }
};
/**
解题思路：
    这道题的关键是不让用额外的空间，C++会很简单，每次迭代观察相邻两个元素就可以了，C的话会很麻烦还要移动剩余元素
 */
