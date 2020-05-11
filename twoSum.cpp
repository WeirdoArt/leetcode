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
