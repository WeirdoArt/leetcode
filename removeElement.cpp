// Approach 1: Two Pointers
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        
        int i = 0;
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            if (*iter != val) {
                nums[i++] = *iter;
            }
        }
        return i;
    }
};
/**
解题思路：
    这是leetcode里的方法，但是这个方法不会删除实际vector，因为传的是referene，个人感觉有点儿偏离题目，
    不过也是个思路，这个方法就是双指针的思路，链表操作里常用的，一个快指针，一个慢指针
 */

// 就地删除
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        
        for (auto iter = nums.begin(); iter != nums.end(); ) { // !!!
            if (*iter == val) {
                nums.erase(iter); // !!!C++的坑，不要说你没遇到过，我是遇到过！！！
            }
            else {
                ++iter;
            }
        }
        return nums.size();
    }
};
/**
解题思路：
    刚开始这到底简单到让我怀疑自己，后来出问题才知道，又一些细节需要注意，例如C++的坑！
    erase 删除元素后会返回已删除元素的下一个元素的迭代器，如果删除最后一个元素，返回的是end(),
    然后再++肯定出错，所以for循环中不能使用++，其实最好的方法是使用while循环，不过我还是用for循环，
    把这个问题暴露出来，希望跟我一样遇到这个问题的同学能注意到这个点,
    我也想到了利用反向迭代器，但是貌似没有适配反向迭代器的erase...，所以之前我说过，C++的STL接口设计的很不友好。。。
 */ 
