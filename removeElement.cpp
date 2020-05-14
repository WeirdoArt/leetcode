class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        
        for (auto iter = nums.begin(); iter != nums.end(); ) {
            if (*iter == val) {
                nums.erase(iter); // !!!巨坑，erase删除元素后会返回已删除元素的下一个元素的迭代器，如果删除最后一个元素，返回的是end(),然后再++肯定出错，所以for循环中不能使用++
            }
            else {
                ++iter;
            }
        }
        return nums.size();
    }
};
