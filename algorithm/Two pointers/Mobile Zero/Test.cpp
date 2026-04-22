#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int dest = -1;
        for (size_t cur = 0; cur < nums.size(); ++cur) {
            if (nums[cur] != 0) {
                swap(nums[dest++], nums[cur]);
            }
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {0, 1, 0, 3, 12};

    std::cout << "Before: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sol.moveZeroes(nums);

    std::cout << "After: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}