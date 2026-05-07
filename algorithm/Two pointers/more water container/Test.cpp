#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1,ret=0;
        while(left<right)
        {
            int v=min(height[left],height[right])*(right-left);
            ret=max(v,ret);
            //移动指针
            if(height[left]<height[right])left++;
            else right--;
        }
        return ret;
    }
};

int main() {
    Solution sol;

    // Test case 1: basic
    vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1 (expected 49): " << sol.maxArea(h1) << endl;

    // Test case 2: two elements
    vector<int> h2 = {1, 1};
    cout << "Test 2 (expected 1): " << sol.maxArea(h2) << endl;

    // Test case 3: increasing heights
    vector<int> h3 = {1, 2, 3, 4, 5};
    cout << "Test 3 (expected 6): " << sol.maxArea(h3) << endl;

    // Test case 4: decreasing heights
    vector<int> h4 = {5, 4, 3, 2, 1};
    cout << "Test 4 (expected 6): " << sol.maxArea(h4) << endl;

    // Test case 5: equal heights
    vector<int> h5 = {4, 4, 4, 4};
    cout << "Test 5 (expected 12): " << sol.maxArea(h5) << endl;

    // Test case 6: zero height
    vector<int> h6 = {0, 1, 0};
    cout << "Test 6 (expected 0): " << sol.maxArea(h6) << endl;

    return 0;
}