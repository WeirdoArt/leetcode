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

// 以下解决方式会超出时间限制(Time Limit Exceeded)
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


// hash map解决方法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>m;
        vector<int>vecRet;
        for(int i = 0; i < nums.size(); ++i) {
            int nTmp = target - nums[i];
            if(m.find(nTmp) != m.end()) {
                vecRet.push_back(m.find(nTmp)->second);
                vecRet.push_back(i);
                return vecRet;
            }
            m.insert(pair<int, int>(nums[i], i));
        }
        return vecRet;
    }
};
