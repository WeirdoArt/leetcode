// 动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int max_ans = dp[0];
        for(int i = 1; i<nums.size(); ++i){
            dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
            max_ans = max(max_ans, dp[i]);
        }
        return max_ans;
    }
};

// 贪婪
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans;
        ans = nums[0];
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            ans = max(ans,sum);
            sum = max(sum,0);
        }
        return ans;
    }
};
