#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int len = INT_MAX;
        int n = nums.size();

        for (int right = 0; right < n; ++right) {
            // 1. 扩展右边界，累加和
            sum += nums[right];

            // 2. 当 sum >= target 时，尝试收缩左边界
            while (sum >= target) {
                // 更新最小长度
                len = min(len, right - left + 1);
                // 收缩左边界
                sum -= nums[left++];
            }
        }

        // 如果 len 还是 INT_MAX，说明没有符合条件的子数组，返回 0
        return len == INT_MAX ? 0 : len;
    }
};

int main() {
    Solution sol;

    // Test case 1: standard
    vector<int> n1 = {2, 3, 1, 2, 4, 3};
    cout << "Test 1 (expected 2): " << sol.minSubArrayLen(7, n1) << endl;

    // Test case 2: single element enough
    vector<int> n2 = {1, 4, 4};
    cout << "Test 2 (expected 1): " << sol.minSubArrayLen(4, n2) << endl;

    // Test case 3: no solution
    vector<int> n3 = {1, 1, 1, 1};
    cout << "Test 3 (expected 0): " << sol.minSubArrayLen(10, n3) << endl;

    // Test case 4: exact match
    vector<int> n4 = {1, 2, 3, 4, 5};
    cout << "Test 4 (expected 3): " << sol.minSubArrayLen(9, n4) << endl;

    // Test case 5: whole array
    vector<int> n5 = {1, 1, 1};
    cout << "Test 5 (expected 3): " << sol.minSubArrayLen(3, n5) << endl;

    // Test case 6: large numbers
    vector<int> n6 = {10, 5, 13, 4, 8, 4, 5, 10, 5};
    cout << "Test 6 (expected 3): " << sol.minSubArrayLen(23, n6) << endl;

    return 0;
}