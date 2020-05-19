// Approach 1: Brute Force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>vecIdx;
        for(int i = 0; i < nums.size() - 1; ++i) {
            for(int j = i + 1; j < nums.size(); ++j) { // Note: 这里j=i+1，因为不能使用同一个数
                if(nums[i] + nums[j] == target) {
                    vecIdx.push_back(i);
                    vecIdx.push_back(j);
                    return vecIdx;
                }
            }
        }
        return vecIdx;
    }
};
/**
解题思路：
    暴力求解就是两层迭代，外层迭代遍历“每个元素”（最后一个元素不需要做计算），
    内层迭代遍历“剩余元素”（从外层迭代的索引的下一个位置到最后），
    将内层迭代的每个元素与外层迭代的“当前”元素做运算，满足条件立即返回；
 */

// Approach 3: One-pass Hash Table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vecIdx;
        map<int, int>mapCmp;        
        for (int i = 0; i < nums.size(); ++i) {
            int cmp = target - nums[i]; // 求补码
            if (mapCmp.find(cmp) != mapCmp.end()) {
                vecIdx.push_back(mapCmp.find(cmp)->second);
                vecIdx.push_back(i);
                return vecIdx;
            }
            mapCmp.insert(pair<int, int>(nums[i], i));
        }
        return vecIdx;
    }
};
/**
解题思路：
    关键点1：补码机制（这里的补码指差值）
    关键点2：利用hash table的机制（C++里就用map）
    在迭代每个元素的同时，将（元素，下标）插入map，并在此过程中检查“差值元素”是否已存在于map中，
    如果存在，如果存在标识满足条件立即返回当前下标与map中“差值元素”的下标
 */
