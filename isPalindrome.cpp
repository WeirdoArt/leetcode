// Approach 1: Revert half of the number
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int rev = 0;
        while(x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return x == rev || x == rev / 10;
    }
};
/**
解题思路：
    关键点1：边界考虑
    关键点2：/ 和 % 的运算特性
    关键点3：还原一半的条件（while(x > rev)）
    首次要处理边界，负数直接返回，正整数需要考虑个位为0的情况，
    还是利用 / 和 % 的特性反转整数，但是判断是否为回文数，只需要反转一半就好了（while (x > rev)）
 */
