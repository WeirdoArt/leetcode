class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        for (vector<int>::iterator iter = nums.begin(); 
             iter != nums.end(), iter + 1 != nums.end(); ++iter) {
            if (*iter == *(iter + 1)) {
                nums.erase(iter + 1);
                iter--;
            }
            
        }
        return nums.size();
    }
};
