#include <vector>
#include <iostream>

class Solution {
public:
    void duplicateZeros(std::vector<int>& arr) {
        int dest=-1;int cur=0;int n=arr.size();
        //1.往后确定复写后末位置
        while(cur<n)
        {
            if(arr[cur]!=0)dest++;
            else dest+=2;
            if(dest>=n-1)break;
            cur++;
        }
        //2.处理边界情况
        if(dest>=n)
        {
            arr[n-1]=0;
            dest=n-2;
            cur--;
        }
        //3.从后往前调整
        while(cur>=0)
        {
            if(arr[cur]!=0)arr[dest--]=arr[cur];
            else
            {
                arr[dest--]=arr[cur];
                arr[dest--]=arr[cur];
            }
            cur--;
        }
    }
};

int main() {
    Solution sol;

    // 测试用例1
    std::vector<int> arr1 = {1, 0, 2, 3, 0, 4, 5, 0};
    std::cout << "测试用例1 - 原始数组: ";
    for (int num : arr1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sol.duplicateZeros(arr1);

    std::cout << "处理后数组: ";
    for (int num : arr1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 测试用例2
    std::vector<int> arr2 = {1, 2, 3};
    std::cout << "\n测试用例2 - 原始数组: ";
    for (int num : arr2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sol.duplicateZeros(arr2);

    std::cout << "处理后数组: ";
    for (int num : arr2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 测试用例3 - 边界情况
    std::vector<int> arr3 = {0, 0, 0, 1, 2};
    std::cout << "\n测试用例3 - 原始数组: ";
    for (int num : arr3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sol.duplicateZeros(arr3);

    std::cout << "处理后数组: ";
    for (int num : arr3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}