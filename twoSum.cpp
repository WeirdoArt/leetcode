// Approach 1: Brute Force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ret;
        for(int i = 0; i < nums.size() - 1; ++i) {
            for(int j = i + 1; j < nums.size(); ++j) { // Note: 这里j=i+1，因为不能使用同一个数
                if(nums[i] + nums[j] == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }
};
/**
解题思路：
    暴力求解就是两层迭代，外层迭代遍历“每个元素”（最后一个元素不需要做计算），
    内层迭代遍历“剩余元素”（从外层迭代的索引的下一个位置到最后），
    将内层迭代的每个元素与外层迭代的“当前”元素做运算，满足条件立即返回；
 */

// 以下解决方式会超出时间限制(Time Limit Exceeded)（自己写的，想法是把上面双循环改成单循环）
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ret;
        
        int i = 0, j = 0;
        while(i < nums.size()) {
            j = i + 1;
            if(nums[i] + nums[j] == target && i != j) {
                ret.push_back(i);
                ret.push_back(j);
                break;
            }
            else {
                ++j;
                --i;
            }
            ++i;
        }
        return ret;
    }
};


/* 
[2,7,11,15]
9
*/

// Approach 3: One-pass Hash Table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vecret;
        map<int, int>m;        
        for (int i = 0; i < nums.size(); ++i) {
            int cmp = target - nums[i]; // 求补码
            if (m.find(cmp) != m.end()) {
                vecret.push_back(m.find(cmp)->second);
                vecret.push_back(i);
                return vecret;
            }
            m.insert(pair<int, int>(nums[i], i));
        }
        return vecret;
    }
};
/**
解题思路：
    关键点1：补码机制（这里的补码指差值）
    关键点2：利用hash table的机制（C++里就用map）
    在迭代每个元素的同时，将（元素，下标）插入map，并在此过程中检查“差值元素”是否已存在于map中，
    如果存在，如果存在标识满足条件立即返回当前下标与map中“差值元素”的下标
 */
