// Approach 1: Pop and Push Digits & Check before Overflow
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10; 
            x /= 10;
            // 这里判断正整数将高位与低位拆开，那么就又两种情况（> 和 ≤），大于的话表示溢出直接返回
            // 如果是小于不用考虑，继续迭代，如果相等，需要再判断低位是否溢出
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            // 判断负整数是否溢出，逻辑是一样的，需要注意的是负整数最低位多一位
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
/**
解题思路：
    关键点1：利用除法和求模运算将整数高低位交换
    关键点2：处理溢出的情况
    反转整数首先应该想到的就是除法+求模运算，除法是整除，求模是求余数，利用这些特性就可以将整数反转；
    但是反转过程中需要考虑边界问题，int（2147483647~-2147483648），每次迭代中 rev 和 pop是个中间结果
    用这些中间结果来判定是否溢出，需要把边界做适当的运算使边界和这些中间结果属于同一条件下，然后判定是否溢出
 */
