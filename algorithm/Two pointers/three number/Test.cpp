#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ret;

        //1.排序
        sort(nums.begin(),nums.end());
        
        //2.for循环
        for(int i=0;i<nums.size();)
        {
            if(nums[i]>0)break;//小优化
            int left=i+1;int right=nums.size()-1;int target=-nums[i];
            
            while(left<right)
            {
                int sum=nums[left]+nums[right];
                if(sum>target)right--   ;
                else if(sum<target)left++; 
                else
                {
                    ret.push_back({nums[i],nums[left],nums[right]});
                    left++,right--;
                    while(left<right && nums[left]==nums[left-1])left++;
                    while(left<right && nums[right]==nums[right+1])right--;
                }                
            }
            //去重i
            i++;
            while(i<nums.size() && nums[i]==nums[i-1])i++;
        }
        return ret;
    }
};

int main() {
    Solution sol;

    // Test case 1: standard case
    vector<int> n1 = {-1, 0, 1, 2, -1, -4};
    auto r1 = sol.threeSum(n1);
    cout << "Test 1 (expected [[-1,-1,2],[-1,0,1]]):" << endl;
    for (auto& v : r1) cout << "  [" << v[0] << "," << v[1] << "," << v[2] << "]" << endl;

    // Test case 2: no solution
    vector<int> n2 = {1, 2, 3, 4};
    auto r2 = sol.threeSum(n2);
    cout << "Test 2 (expected []): " << (r2.empty() ? "empty" : "has result") << endl;

    // Test case 3: all zeros
    vector<int> n3 = {0, 0, 0};
    auto r3 = sol.threeSum(n3);
    cout << "Test 3 (expected [[0,0,0]]):" << endl;
    for (auto& v : r3) cout << "  [" << v[0] << "," << v[1] << "," << v[2] << "]" << endl;

    // Test case 4: multiple duplicates
    vector<int> n4 = {0, 0, 0, 0};
    auto r4 = sol.threeSum(n4);
    cout << "Test 4 (expected [[0,0,0]]):" << endl;
    for (auto& v : r4) cout << "  [" << v[0] << "," << v[1] << "," << v[2] << "]" << endl;

    // Test case 5: all negative
    vector<int> n5 = {-5, -4, -3, -2, -1};
    auto r5 = sol.threeSum(n5);
    cout << "Test 5 (expected []): " << (r5.empty() ? "empty" : "has result") << endl;

    // Test case 6: larger set
    vector<int> n6 = {-2, 0, 1, 1, 2};
    auto r6 = sol.threeSum(n6);
    cout << "Test 6 (expected [[-2,0,2],[-2,1,1]]):" << endl;
    for (auto& v : r6) cout << "  [" << v[0] << "," << v[1] << "," << v[2] << "]" << endl;

    return 0;
}