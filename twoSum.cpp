// 暴力求解
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ret;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i; j < nums.size(); ++j) {
                if(nums[i] + nums[j] == target && i != j) {
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }
};

// 以下解决方式会超出时间限制(Time Limit Exceeded)（自己写的，想法是双循环改成单循环）
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

// hash map解决方法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>m;
        vector<int>vecRet;
        for(int i = 0; i < nums.size(); ++i) {
            int nTmp = target - nums[i]; // loop1[tmp = 7], loop2[tmp = 2]
            if(m.find(nTmp) != m.end()) { // 如果找到，代表已经存在
                vecRet.push_back(m.find(nTmp)->second); // 0
                vecRet.push_back(i); // 1
                return vecRet;
            }
            // loop1[m = (2, 0)]
            m.insert(pair<int, int>(nums[i], i)); // vector的值当作key，下标当作value插入到map, 因为要返回下标数组，所以这里的value要存vector的下标
        }
        return vecRet;
    }
};
