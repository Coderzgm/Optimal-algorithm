#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ret;

        int n=nums.size();
        for(int i=0;i<n;)
        {
            for(int j=i+1;j<n;)
            {
                long long aim=(long long)target-nums[i]-nums[j];
                int left=j+1,right=n-1;
                while(left<right)
                {
                    if(aim<nums[left]+nums[right])
                    {
                        right--;
                    }
                    else if(aim>nums[left]+nums[right])
                    {
                        left++;
                    }
                    else
                    {
                        ret.push_back({nums[i],nums[j],nums[left++],nums[right--]});
                        while(nums[left]==nums[left-1]&&left<right)left++;
                        while(nums[right]==nums[right+1]&&left<right)right--;
                    }
                }
                j++;
                while(j<n&&nums[j]==nums[j-1])j++;
            }
            i++;
            while(i<n&&nums[i]==nums[i-1])i++;
        }
        return ret;
    }
};

int main() {
    Solution sol;

    // Test case 1: standard case
    vector<int> n1 = {1, 0, -1, 0, -2, 2};
    auto r1 = sol.fourSum(n1, 0);
    cout << "Test 1 (expected [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]):" << endl;
    for (auto& v : r1) cout << "  [" << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "]" << endl;

    // Test case 2: no solution
    vector<int> n2 = {1, 2, 3, 4};
    auto r2 = sol.fourSum(n2, 0);
    cout << "Test 2 (expected []): " << (r2.empty() ? "empty" : "has result") << endl;

    // Test case 3: all same
    vector<int> n3 = {0, 0, 0, 0};
    auto r3 = sol.fourSum(n3, 0);
    cout << "Test 3 (expected [[0,0,0,0]]):" << endl;
    for (auto& v : r3) cout << "  [" << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "]" << endl;

    // Test case 4: large target with negatives
    vector<int> n4 = {-3, -2, -1, 0, 0, 1, 2, 3};
    auto r4 = sol.fourSum(n4, 0);
    cout << "Test 4 (expected multiple): " << r4.size() << " results" << endl;
    for (auto& v : r4) cout << "  [" << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "]" << endl;

    // Test case 5: overflow test
    vector<int> n5 = {1000000000, 1000000000, 1000000000, 1000000000};
    auto r5 = sol.fourSum(n5, -294967296);
    cout << "Test 5 (expected []): " << (r5.empty() ? "empty" : "has result") << endl;

    // Test case 6: two elements each
    vector<int> n6 = {2, 2, 2, 2, 2};
    auto r6 = sol.fourSum(n6, 8);
    cout << "Test 6 (expected [[2,2,2,2]]):" << endl;
    for (auto& v : r6) cout << "  [" << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "]" << endl;

    return 0;
}