// Brute-Force
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        if (A.empty() || A.size() > 30000) {
            return 0;
        }

        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            int rem = A[i];
            if (rem % K == 0) {
                res++;
            }
            for (int j = i + 1; j < A.size(); ++j) {
                rem += A[j];
                if (rem % K == 0) {
                    res++;
                }
            }
        }
        return res;
    }
};

// 哈希表 + 逐一统计
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> record = {{0, 1}};
        int sum = 0, ans = 0;
        for (int elem: A) {
            sum += elem;
            // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
            int modulus = (sum % K + K) % K;
            if (record.count(modulus)) {
                ans += record[modulus];
            }
            ++record[modulus];
        }
        return ans;
    }
};

// 哈希表 + 单次统计
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> record = {{0, 1}};
        int sum = 0;
        for (int elem: A) {
            sum += elem;
            // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
            int modulus = (sum % K + K) % K;
            ++record[modulus];
        }

        int ans = 0;
        for (auto [x, cx]: record) {
            ans += cx * (cx - 1) / 2;
        }
        return ans;
    }
};
